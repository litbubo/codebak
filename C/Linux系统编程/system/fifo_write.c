#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

int main(int argc, char **argv)
{
    int ret = mkfifo("test_fifo", 0666);
    if (ret == -1)
    {
        perror("mkfifo");
        exit(1);
    }
    printf("创建管道成功！\n");
    int fdret = open("test_fifo", O_WRONLY);
    if (fdret == -1)
    {
        perror("open");
        exit(1);
    }
    printf("打开管道成功！\n");

    int n = 30;
    char buf[1024];
    while (n--)
    {
        memset(buf, 0, sizeof(buf));
        sprintf(buf, "我在写管道......%d\n", n);
        write(fdret, buf, sizeof(buf));
        sleep(1);
    }
    close(fdret);
    unlink("./test_fifo");
    return 0;
}