#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "clear.h"

void clear(void)
{
    pid_t pid = fork();
    if (pid < 0) {
        perror("fork failed");
    } else if (pid == 0) {
        char *args[] = {"clear", NULL};
        execvp(args[0], args);
        perror("execvp failed");
        exit(1);
    } else {
        wait(NULL);
    }
}
