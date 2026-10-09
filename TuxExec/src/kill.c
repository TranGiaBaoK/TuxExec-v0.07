#include "kill.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

void killps(void) {
    char pid_str[16];
    printf("Enter PID: ");
    fflush(stdout);

    if (fgets(pid_str, sizeof(pid_str), stdin) == NULL) return;
    pid_str[strcspn(pid_str, "\r\n")] = '\0';

    pid_t pid = fork();
    if (pid < 0) {
        perror("[-] Fork failed");
        return;
    }

    if (pid == 0) {
        char *args[] = {"kill", "-9", pid_str, NULL};
        execvp("kill", args);
        perror("[-] execvp failed");
        exit(EXIT_FAILURE);
    } else {
        int status;
        waitpid(pid, &status, 0);
        if (!WIFEXITED(status) || WEXITSTATUS(status) != 0) {
            printf("[-] Failed to kill process %s.\n", pid_str);
        }
    }
}
