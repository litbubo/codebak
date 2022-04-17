#include "stdio.h"
#include "stdlib.h"
#include "unistd.h"
#include "string.h"
#include "fcntl.h"
#include "sys/types.h"
#include "sys/stat.h"

int main(int argc, char **argv)
{
    int fd = open("2.txt", O_RDWR);
    if(fd == -1) 
    {
        perror("2.txt");
        return -1;
    }
    int fd2 = fcntl(fd, F_DUPFD);
    printf("fd == %d, fd2 == %d\n", fd, fd2);
    dup2(fd, fd2);
    lseek(fd, 0, SEEK_END);
    write(fd, "hello", 5);
    close(fd);
    write(fd2, "world", 5);
    close(fd2);

    int fd3 = open("1.txt", O_RDWR);
    if(fd3 == -1) 
    {
        perror("1.txt");
        return -1;
    }
    int flags = fcntl(fd3, F_GETFL);
    flags |= O_APPEND;
    //flags |= O_RDWR;
    fcntl(fd3, F_SETFL, flags);
    int ret = write(fd3, "hello", 5);
    if(ret == -1)
    {
        perror("1.txt");
    }

    close(fd3);
    return 0;
}