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
        printf("-------------------------------\n");
        sleep(3);
        printf("child ID == %d\n", getpid());
        printf("child has changed group ID to %d\n", getpgid(0));


        exit(0);
    }
    else
    {
        sleep(1);
        setpgid(pid, pid);
        sleep(5);
        printf("-------------------------------\n");
        printf("parent ID == %d\n", getpid());
        printf("parentis parent ID == %d\n", getppid());
        printf("parent group ID == %d\n", getpgid(0));

        sleep(5);
        printf("-------------------------------\n");
        setpgid(getpid(), getppid());
        printf("parent group ID has changed to == %d\n", getpgid(0));
    }
    while (1)
            ;
}