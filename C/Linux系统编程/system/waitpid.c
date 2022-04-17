#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char **argv)
{
    int n = 5;
    pid_t pid, pidq;
    printf("start\n");
    int i;
    for (i = 0; i < n; i++)
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
        }
        else if (pid > 0)
        {
            pidq = pid;
        }
    }
    if (i < 5)
    {
        sleep(i);
        printf("I am a %d child, pid = %d, ppid = %d\n", i, getpid(), getppid());
    }
    else
    {
        pid_t ret;
        do
        {
            if((ret = waitpid(-1, NULL, WNOHANG)) > 0)
            {
                n--;
                printf("回收%d个进程, 进程号%d\n", 5-n, ret);
            }
            else
            {
                //printf("等待\n");
            }
        }while (n > 0);
        sleep(20);
        printf("I am a parent, pid = %d, ppid = %d\n", getpid(), getppid());
    }

    printf("end\n");
}