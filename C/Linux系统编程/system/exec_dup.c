#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(int argc, char **argv)
{
    int fd = open("1.txt", O_WRONLY | O_CREAT | O_TRUNC, 0666);
    if(fd < 0)
    {
        perror("open");
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
        dup2(fd, STDOUT_FILENO);
        execlp("ps", "ps", "aux", NULL);
    }
    else
    {
        sleep(1);
    }
}