#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int var = 666;

int main(int argc, char **argv)
{
    pid_t pid;
    printf("start\n");
    pid = fork();
    if(pid == -1)
    {
        perror("fork");
        exit(1);
    }
    else if (pid == 0)
    {
        var = 777;
        printf("I am a child, pid = %d, ppid = %d, var = %d\n", getpid(), getppid(), var);
    }
    else
    {   
        var = 999;
        printf("I am a parent, pid = %d, ppid = %d, var =%d\n", getpid(), getppid(), var);
        sleep(1);
    }
    printf("end, var = %d\n", var);
}