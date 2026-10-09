#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <ctype.h>
#include "disassembler.h"

void hex_to_bytes(const char *hex_str, unsigned char *out_bytes, size_t *out_len) {
    size_t len = strlen(hex_str);
    size_t clean_len = 0;
    char clean_hex[10000];

    for (size_t k = 0; k < len; k++) {
        char c = hex_str[k];
        if (isxdigit(c)) {
            clean_hex[clean_len++] = c;
        }
    }
    clean_hex[clean_len] = '\0';

    size_t i = 0, j = 0;
    while (i + 1 < clean_len) {
        char byte_str[3] = {clean_hex[i], clean_hex[i+1], '\0'};
        out_bytes[j++] = (unsigned char)strtol(byte_str, NULL, 16);
        i += 2;
    }
    *out_len = j;
}

void tuxexec_disassembler(void) {
    char hex[10000];
    printf("\nTuxExec >> Enter hex string: ");
    
    if (fgets(hex, sizeof(hex), stdin) == NULL) {
        perror("fgets failed");
        return;
    }

    unsigned char binary_code[5000];
    size_t binary_len = 0;
    hex_to_bytes(hex, binary_code, &binary_len);

    if (binary_len == 0) {
        printf("TuxExec: Invalid or empty hex string!\n");
        return;
    }

    FILE *f = fopen("temp_bin", "wb");
    if (!f) {
        perror("fopen failed");
        return;
    }
    fwrite(binary_code, 1, binary_len, f);
    fclose(f);

    pid_t pid = fork();

    if (pid < 0) {
        perror("fork failed");
        exit(1);
    } else if (pid == 0) {
        char *args[] = {"objdump", "-D", "-b", "binary", "-m", "i386:x86-64", "temp_bin", NULL};
        execvp(args[0], args);
        
        perror("objdump execution failed or not supported");
        exit(1);
    } else {
        int status;
        waitpid(pid, &status, 0);
        remove("temp_bin");
    }
}
