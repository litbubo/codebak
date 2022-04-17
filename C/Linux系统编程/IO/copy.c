#include "stdio.h"
#include "stdlib.h"
#include "unistd.h"
#include "string.h"
#include "fcntl.h"
#include "sys/types.h"
#include "sys/stat.h"

int main(int argc, char **argv)
{
    int fd1 = open("[08]《三体Ⅲ死神永生》.txt", O_RDONLY);
    if(fd1 == -1)
    {
        perror("open-readfile");
        return -1;
    }
    else
    {
        printf("打开成功fd == %d\n", fd1);
    }

    int fd2 = open("copy.txt", O_CREAT | O_RDWR, 0666);
    if(fd2 == -1)
    {
        perror("open-copyfile");
        return -1;
    }
    else
    {
        printf("创建成功fd == %d\n", fd2);
    }
    char buf[1024];
    int len = -1;
    while( (len = read(fd1, buf, sizeof(buf))) > 0)
    {
        write(fd2, buf, len);
        printf("%d\n", len);
    }
    close(fd2);
    close(fd1);
    return 0;

}