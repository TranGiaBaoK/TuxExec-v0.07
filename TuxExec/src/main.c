#include <stdio.h>
#include <string.h>
#include "system_tools.h"
#include "c_cpp_helper.h"
#include "kill.h"
#include "ipscan.h"
#include "top_ps.h"
#include "disassembler.h"
#include "calculator.h"
#include "create_icon.h"
#include "clear.h"

void help(void)
{
    printf("TuxExec 0.07 - POSIX System Utility\n");
    printf("Options:\n");
    printf("wslinstubuntu:    Install the Wsl for Windows\n");
    printf("rm:               Remove file with path in Unix and Unix Like\n");
    printf("exit:             Exit the system\n");
    printf("systeminfo:       Display Kernel and OS release information\n");
    printf("top_ps:           Launch system process monitor\n");
    printf("ipscan:           Scan local subnet IP addresses\n");
    printf("c_cpp_helper:     Tutorial how to use C and Cpp\n");
    printf("killps:           Interactive process manager\n");
    printf("disassembler:     Disassembler hex to binary\n");
    printf("calculator:       Calculator answers of math problems\n");
    printf("create_icon:      Make a icon like geometry, cute, .....\n");
    printf("clear:            clear Terminal\n");
    printf("--help:           Show this help menu\n");
}

int main(void) {
    char user_input[256];

    printf("command --help for helper command\n");
    while (1) {
        printf("TuxExec CMD: ");
        fflush(stdout);

        if (fgets(user_input, sizeof(user_input), stdin) == NULL) {
            break;
        }

        user_input[strcspn(user_input, "\r\n")] = '\0';

        if (user_input[0] == '\0') {
            continue;
        }

        if (strcmp(user_input, "inst") == 0) {
            inst();
        } else if (strcmp(user_input, "rm") == 0) {
            rm();
        } else if (strcmp(user_input, "systeminfo") == 0) {
            systeminfo();
        } else if (strcmp(user_input, "c_cpp_helper") == 0) {
            c_cpp_helper();
        } else if (strcmp(user_input, "killps") == 0) {
            killps();
        } else if (strcmp(user_input, "ipscan") == 0 || strcmp(user_input, "ip_scan") == 0) {
            ipscan();
        } else if (strcmp(user_input, "exit") == 0) {
            break;
        } else if (strcmp(user_input, "top_ps") == 0 || strcmp(user_input, "topps") == 0) {
            top_ps();
        } else if (strcmp(user_input, "calculator") == 0) {
            run_calculator();
        } else if (strcmp(user_input, "create_icon") == 0) {
            create_icon();
        } else if (strcmp(user_input, "disassembler") == 0) {
            tuxexec_disassembler();
        } else if (strcmp(user_input, "--help") == 0) {
            help();    
        } else if (strcmp(user_input, "clear") == 0) {
            clear();
	    help();
        } else {
            printf("not found ***\n");
        }
    }
    return 0;
}
