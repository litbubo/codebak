#include "stdio.h"
#include "stdlib.h"
#include "sys/types.h"
#include "sys/stat.h"
#include "sys/stat.h"
#include "fcntl.h"
#include "unistd.h"

int main(int argc, char **argv)
{
    int fd = open("1.txt", O_RDWR);
    if (fd == -1) 
    {
        printf("文件打开失败\n");
    }
    else
    {
        printf("打开成功 fd = %d" , fd);
    }
    close(fd);
    return 0;
}