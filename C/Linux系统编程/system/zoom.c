#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char **argv)
{
    pid_t pid;
    printf("start\n");
    pid = fork();
    if (pid == -1)
    {
        perror("fork");
        exit(1);
    }
    else if (pid == 0)
    {
        printf("I am a child, pid = %d, ppid = %d\n", getpid(), getppid());
        sleep(5);
        printf("I am a child, going to die\n");
    }
    else
    {
        while (1)
        {
            printf("I am a parent, pid = %d, ppid = %d\n", getpid(), getppid());
            sleep(1);
        }
    }
    printf("end\n");
}