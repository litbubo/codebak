#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char **arg)
{
    pid_t pid = 0;
    pid = fork();

    if (pid == -1)
    {
        perror("fork");
        exit(1);
    }
    else if (pid == 0)
    {
        execlp("ls", "ls", "-l", "-a", NULL);
        //execl("./while", "while", NULL);
    }
    else
    {
        sleep(1);
    }
}