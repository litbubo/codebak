#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

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
        //int a = 5/0; 
        //char *p = "123456";
        //p[0] = '7';
        printf("I am a child, pid = %d, ppid = %d\n", getpid(), getppid());
        sleep(60);
        printf("I am a child, going to die\n");
        exit(100);
    }
    else
    {
        int status;
        pid_t waitpid = wait(&status);

        if (waitpid == -1)
        {
            perror("wait");
            exit(1);
        }

        if(WIFEXITED(status))
        {
            printf("child wait id = %d\n", WEXITSTATUS(status));
        }
        if (WIFSIGNALED(status))
        {
            printf("child kill by %d\n", WTERMSIG(status));
        }
        while (1)
        {
            printf("I am a parent, pid = %d, ppid = %d\n", getpid(), getppid());
            sleep(1);
        }
    }
    printf("end\n");
}