#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char **argv)
{
    pid_t pid;
    printf("start\n");
    int i;
    for (i = 0; i < 5; i++)
    {
        pid = fork();
        if (pid == -1)
        {
            perror("fork");
            exit(1);
        }
        else if (pid == 0)
        {
            break;
            //printf("I am a %d child, pid = %d, ppid = %d\n", i, getpid(), getppid());
        }
    }
    if (i < 5)
    {
        sleep(i);
        printf("I am a %d child, pid = %d, ppid = %d\n", i, getpid(), getppid());
    }
    else
    {
        sleep(i);
        printf("I am a parent, pid = %d, ppid = %d\n", getpid(), getppid());
    }

    printf("end\n");
}