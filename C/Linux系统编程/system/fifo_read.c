#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char **argv)
{
    int fdret = open("test_fifo", O_RDONLY);
    if (fdret == -1)
    {
        perror("open");
        exit(1);
    }
    printf("打开管道成功！\n");

    char buf[1024];
    while (1)
    {
        memset(buf, 0, sizeof(buf));
        int ret = read(fdret, buf, sizeof(buf));
        if (ret == 0)
            break;
        printf("%s", buf);
    }
    close(fdret);
    unlink("test_fifo");
    return 0;
}