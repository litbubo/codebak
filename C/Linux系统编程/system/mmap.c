#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>

int var = 100;

int main(int argc, char **argv)
{
    int ret, fd;
    fd = open("test_mmap.txt", O_CREAT | O_RDWR | O_TRUNC, 0666);
    if (fd == -1)
    {
        perror("open_mmap");
        exit(1);
    }
    ret = ftruncate(fd, 20);
    if (ret == -1)
    {
        perror("ftruncate");
        exit(1);
    }
    unlink("test_mmap.txt");

    int *p = mmap(NULL, 20, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
    if (p == MAP_FAILED)
    {
        perror("mmap");
        exit(1);
    }
    close(fd);

    pid_t pid = fork();
    if (pid == -1)
    {
        perror("fork");
        exit(1);
    }
    else if (pid == 0)
    {
        *p = 2000;
        var = 1000;
        printf("child, *p = %d, var = %d\n", *p, var);
    }
    else
    {
        //*p = 1000;
        sleep(1);
        printf("parent, *p = %d, var = %d\n", *p, var);
        ret = munmap(p, 20);
        if (ret == -1)
        {
            perror("munmap");
            exit(1);
        }
    }
    return 0;
}