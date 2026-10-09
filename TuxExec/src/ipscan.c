#include "ipscan.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

void ipscan(void)
{
	pid_t pid = fork();
	if (pid == 0) {
		char *args[] = {
            "sh", 
            "-c", 
            "ip n && ip a && ip -br a", 
            NULL
        };
		execvp(args[0], args);
		perror("execvp failed");
		exit(1);
	} else if (pid < 0) {
		perror("failed pid");
	} else {
		wait(NULL);
	}
}
