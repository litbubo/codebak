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

    fd = open("/dev/zero", O_RDWR);

    int *p = mmap(NULL, 200, PROT_READ | PROT_WRITE, MAP_SHARED | MAP_ANONYMOUS, fd, 0);
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