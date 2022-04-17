#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/time.h>
#include <unistd.h>
#include <errno.h>
#include <sys/wait.h>

int main(int argc, char **argv)
{
    pid_t pid;
    pid = fork();
    if (pid < 0)
    {
        perror("fork");
        exit(1);
    }
    else if (pid == 0)
    {
        printf("child ID == %d\n", getpid());
        printf("child group ID == %d\n", getpgid(0));
        printf("child group ID == %d\n", getpgrp());
        printf("session-------------------------------\n");
        sleep(3);
        printf("Session ID of child is %d\n", getsid(0));
        setsid();
        printf("changed:\n");
        printf("child process PID is %d\n", getpid());
        printf("Group ID of child is %d\n", getpgid(0));
        printf("Session ID of child is %d\n", getsid(0));


        exit(0);
    }
    while (1)
            ;
}