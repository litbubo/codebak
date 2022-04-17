#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
    int piefd[2];
    int pieret = pipe(piefd);
    if (pieret == -1)
    {
        perror("pipe");
        exit(1);
    }
    pid_t pid = fork();
    if (pid == -1)
    {
        perror("fork");
        exit(1);
    }
    else if (pid == 0)
    {
        sleep(5);
        close(piefd[0]);
        dup2(piefd[1], STDOUT_FILENO);
        execlp("ps", "ps", NULL);
        return 0;
    }
    else
    {
        close(piefd[1]);
        char buf[4096];
        while (1)
        {
            memset(buf, 0, sizeof(buf));
            int ret = read(piefd[0], buf, sizeof(buf));
            if (ret == 0)
            {
                break;
            }
            printf("%s", buf);
        }
        wait(NULL); 
    }
}
