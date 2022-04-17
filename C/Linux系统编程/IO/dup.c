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
    if (fd == -1) 
    {
        perror("open");
        return -1;
    }
    int fd2 = dup(fd);
    printf("fd == %d, fd2 == %d\n", fd, fd2);
    const char *str = "12345";
    write(fd, str, strlen(str));
    const char *str2 = "678910";
    write(fd, str2, strlen(str2));
    close(fd);
}
    