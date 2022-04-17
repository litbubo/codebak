#include "stdio.h"
#include "stdlib.h"
#include "unistd.h"
#include "string.h"
#include "fcntl.h"
#include "sys/types.h"
#include "sys/stat.h"

int main(int argc, char **argv)
{
    int fd = open("2.txt", O_CREAT | O_EXCL | O_RDWR , 0664);
    if (fd == -1) 
    {
        printf("文件打开失败, 已经创建了\n");
    }
    else
    {
        printf("文件创建成功 fd == %d\n", fd);
    }
    close(fd);
    return 0;
    
}