#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

void top_ps(void)
{
    pid_t pid = fork();

    if (pid < 0) {
        perror("fork failed");
        return;
    } 
    else if (pid == 0) {
        char *args[] = {"sh", "-c", "top && ps", NULL};
        execvp(args[0], args);
        perror("execvp failed");
        exit(EXIT_FAILURE);
    } 
    else {
        wait(NULL);
    }
}
