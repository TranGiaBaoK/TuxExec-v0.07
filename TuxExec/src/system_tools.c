#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <string.h>
#include "system_tools.h"
#include "c_cpp_helper.h"

void input_cmd(char *buf, size_t size)
{
    printf("TuxExec: ");
    if (fgets(buf, size, stdin) != NULL) {
        buf[strcspn(buf, "\n")] = '\0';
    }
}

void inst(void)
{
    char pkgmn[256];
    printf("Linux pkgmn = ? (pacman ,apt , dnf): ");
    fgets(pkgmn, sizeof(pkgmn), stdin);
    pkgmn[strcspn(pkgmn, "\n")] = '\0';
    
    if (strcmp(pkgmn, "apt") == 0) {
        while(1) {
            char apt[512];
            
            printf("pkg install: ");
            fgets(apt, sizeof(apt), stdin);
            apt[strcspn(apt, "\n")] = '\0';
            
            if (strlen(apt) == 0) break;

            pid_t pid = fork();
            if (pid < 0) {
                perror("pid failed");
            }
            else if (pid == 0) {
                char *args[] = {"sudo", "apt", "install", apt, NULL};
                execvp(args[0], args);
                perror("failed execvp");
                exit(1);
            } 
            else {
                wait(NULL);
            }
        }
    }
    else if (strcmp(pkgmn, "dnf") == 0) {
        while(1) {
            char dnf[512];
            
            printf("pkg install: ");
            fgets(dnf, sizeof(dnf), stdin);
            dnf[strcspn(dnf, "\n")] = '\0';
            
            if (strlen(dnf) == 0) break;

            pid_t pid = fork();
            if (pid < 0) {
                perror("failed pid");
            }
            else if (pid == 0) {
                char *args[] = {"sudo", "dnf", "install", dnf, NULL};
                execvp(args[0], args);
                perror("failed execvp");
                exit(1);
            } 
            else {
                wait(NULL);
            }
        }
    } 
    else if (strcmp(pkgmn, "pacman") == 0) {
        char pacman[512];
        
        printf("pkg install: ");
        fgets(pacman, sizeof(pacman), stdin);
        pacman[strcspn(pacman, "\n")] = '\0';
        
        pid_t pid = fork();
        if (pid < 0) {
            perror("failed pid");
        }
        else if (pid == 0) {
            char *args[] = {"sudo", "pacman", "-S", pacman, NULL};
            execvp(args[0], args);
            perror("failed execvp");
            exit(1);
        }
        else {
            wait(NULL);
        }
    }
}

void rm(void)
{
    char rm_file[80];
    printf("file want to remove ? ");
    fgets(rm_file, sizeof(rm_file), stdin);
    rm_file[strcspn(rm_file, "\n")] = '\0';
    
    char sure[10];
    printf("Sure ? Y/n : ");
    fgets(sure, sizeof(sure), stdin);
    sure[strcspn(sure, "\n")] = '\0';
    
    if (strcmp(sure, "y") == 0 || strcmp(sure, "Y") == 0) {
        pid_t pid = fork();
        if (pid == 0) {
            char *args[] = {"sudo", "rm", "-rf", rm_file, NULL};
            execvp(args[0], args);
            perror("failed execvp");
            exit(1);
        }
        else {
            wait(NULL);
        }
    } else {
        return;
    }
}

void systeminfo(void)
{
    pid_t pid = fork();
    if (pid == 0) {
        char *args[] = {"sh", "-c", "ls && lsblk && ls / && uname -a", NULL};
        execvp(args[0], args);
        perror("failed execvp");
        exit(0);
    }
    else {
        wait(NULL);
    }
}

void rep(void)
{
    while(1) {
        char rep_cmd[256];
        printf("\nwhat do you want?\n"
               "<how to see info of system linux>\n"
               "<how to get remove file in this system>\n"
               "<how to get install pkg>\n"
               "c_cpp_helper\n"
               "<how to install wsl in this system \\ powershell>\n"
               "Type command or 'exit' to back: ");
        
        if (fgets(rep_cmd, sizeof(rep_cmd), stdin) == NULL) break;
        rep_cmd[strcspn(rep_cmd, "\n")] = '\0';
        
        if (strcmp(rep_cmd, "how to see info of system linux") == 0) {
            printf("in your terminal , getting command ls, lsblk, ls /, whoami, in this system, you command the systeminfo\n");
        } else if (strcmp(rep_cmd, "how to get remove file in this system") == 0) {
            printf(" in your terminal, getting command rm and your file path wanted to remove, in this system you command rm and write the path file\n");
        } else if (strcmp(rep_cmd, "how to get install pkg") == 0) {
            printf("sudo and your pkg and your pkg , in this system, just command inst and select pkgmanager, select pkg\n");
        } else if (strcmp(rep_cmd, "how to install wsl in this system \\ powershell") == 0) {
            printf(" you really use window bruhhh haha, just command wsl --install Ubuntu or in this system, just command wslinstubuntu\n");
        } else if (strcmp(rep_cmd, "c_cpp_helper") == 0) {
            printf("command the c_cpp_helper for the c and c++ helper\n");
        } else {
            break;
        }
    }
}
