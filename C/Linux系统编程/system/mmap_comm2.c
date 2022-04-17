#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>

struct mystruct
{
    int id;
    char name[10];
    int age;
};

int main(int argc, char **argv)
{
    struct mystruct person;
    int ret, fd;
    fd = open("test_mmap_comm", O_RDONLY);
    if (fd == -1)
    {
        perror("open_mmap");
        exit(1);
    }

    struct mystruct *p = mmap(NULL, sizeof(person), PROT_READ, MAP_SHARED, fd, 0);
    if (p == MAP_FAILED)
    {
        perror("mmap");
        exit(1);
    }
    close(fd);
    while(1)
    {
        printf("ID == %d, Name = %s, Age = %d\n", p->id, p->name, p->age);
        sleep(1);
    }

    ret = munmap(p, 20);
    if (ret == -1)
    {
        perror("munmap");
        exit(1);
    }

    return 0;
}