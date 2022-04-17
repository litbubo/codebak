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
        perror("open");
        return -1;
    }
    //ftruncate(fd, 2048);
    truncate("1.txt", 4096);
    close(fd);
    return 0;
}