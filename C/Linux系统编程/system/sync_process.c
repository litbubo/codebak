#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/time.h>
#include <unistd.h>
#include <errno.h>

int n = 0, flag = 0;

void parent_catch(int signal)
{
    printf("I am parent, pid == %d, n == %d\n", getpid(), n);
    n += 2;
    flag = 1;
    //sleep(1);
}

void child_catch(int signal)
{
    printf("I am child , pid == %d, n == %d\n", getpid(), n);
    n += 2;
    flag = 1;
    //sleep(1);
}

int main(int argc, char **argv)
{
    int ret = 0;
    struct sigaction action;
    pid_t pid = fork();
    if (pid < 0)
    {
        perror("fork");
        exit(1);
    }
    else if (pid > 0)
    {
        action.sa_handler = parent_catch;
        action.sa_flags = 0;
        sigemptyset(&action.sa_mask);
        ret = sigaction(SIGUSR1, &action, NULL);
        if (ret == -1)
        {
            perror("sigaction");
            exit(1);
        }
        n = 1;
        sleep(1);
        parent_catch(0);
        while (1)
        {
            if(flag == 1)
            {
                kill(pid, SIGUSR2);
                flag = 0;
            }
        }
    }
    else
    {
        action.sa_handler = child_catch;
        action.sa_flags = 0;
        sigemptyset(&action.sa_mask);
        ret = sigaction(SIGUSR2, &action, NULL);
        if (ret == -1)
        {
            perror("sigaction");
            exit(1);
        }
        n = 2;
        while (1)
        {
            if(flag == 1)
            {
                kill(getppid(), SIGUSR1);
                flag = 0;
            }
        }
    }
}