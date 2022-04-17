#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/time.h>
#include <unistd.h>
#include <errno.h>
#include <sys/wait.h>

void sigchld_catch(int signal)
{
    pid_t pid;
    int status;
    while ((pid = waitpid(0, &status, WNOHANG)) > 0)
    {
        if (WIFEXITED(status))
        {
            printf("%d子进程退出时候的状态码: %d\n", pid, WEXITSTATUS(status));
        }
        if (WIFSIGNALED(status))
        {
            printf("子进程是被这个信号杀死的: %d\n", WTERMSIG(status));
        }
    }
}

int main(int argc, char **argv)
{
    int ret = 0;
    pid_t pid;
    for (size_t i = 0; i < 10; i++)
    {
        pid = fork();
        if (pid == -1)
        {
            perror("fork");
            exit(1);
        }
        else if (pid == 0)
        {
            sleep(1);
            return i + 1;
        }
    }
    struct sigaction s;
    s.sa_handler = sigchld_catch;
    s.sa_flags = 0;
    sigemptyset(&s.sa_mask);
    ret = sigaction(SIGCHLD, &s, NULL);
    if (ret == -1)
    {
        perror("sigaction");
        exit(1);
    }
    while (1)
    {
        printf("--------------------\n");
        sleep(1);
    }
}