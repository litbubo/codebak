#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc, char **argv)
{
    pid_t pid;
    pid_t q;
    int i = 0;
    for (i = 0; i < 5; i++)
    {
        pid = fork();
        if (pid == 0)
        {
            break;
        }
        else if (i == 2)
        {
            q = pid;
        }
    }

    if (i < 5)
    {
        while (1)
        {
            printf("I am %d child, pid == %d\n", i, getpid());
            sleep(1);
        }
    }
    else
    {
        sleep(10);
        int ret = kill(q, SIGKILL);
        if (ret == -1)
        {
            perror("kill");
            exit(1);
        }
        wait(NULL);
    }

    return 0;
}