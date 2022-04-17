#include "stdio.h"
#include "stdlib.h"
#include "unistd.h"
#include "string.h"
#include "fcntl.h"
#include "sys/types.h"
#include "sys/stat.h"

int main(int argc, char **argv)
{
    int fd = open("1.txt", O_RDWR);
    if (fd == -1) 
    {
        perror("open-file");
        return -1;
    }
    else
    {
        printf("文件打开成功\n");
    }

    int l = lseek(fd, 1000, SEEK_END);
    write(fd, " ", 1);
    close(fd);
}