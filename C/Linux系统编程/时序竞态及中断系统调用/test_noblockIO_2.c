#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>

#define FIFO    "fifo" 

int main(int argc, char **argv)
{

    int ret = mkfifo(FIFO, 0666);
    if(ret < 0)
    {
        perror("mkfifo");
        exit(1);
    }

    int fd = open(FIFO, O_WRONLY);
    if(fd < 0) 
    {
        perror("open");
        exit(1);
    }

    write(STDOUT_FILENO, "mkfifo success\n", sizeof("mkfifo success\n"));

    int cycle = 5;
    while(cycle--)
    {
        write(fd, "a", 1);
        write(STDOUT_FILENO, "a has been write\n", sizeof("a has been write\n"));
        sleep(5);
    }
    close(fd);

    exit(0);
}
