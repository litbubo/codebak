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
    struct mystruct person = {111, "123456", 19};
    int ret, fd;
    fd = open("test_mmap_comm", O_RDWR);
    if (fd == -1)
    {
        perror("open_mmap");
        exit(1);
    }
    /*
    ret = ftruncate(fd, sizeof(person));
    if (ret == -1)
    {
        perror("ftruncate");
        exit(1);
    }
    */
    struct mystruct *p = mmap(NULL, sizeof(person), PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
    if (p == MAP_FAILED)
    {
        perror("mmap");
        exit(1);
    }
    close(fd);
    while(1)
    {
        memcpy(p, &person, sizeof(person));
        person.age++;
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