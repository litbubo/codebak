#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc, char **argv)
{
    alarm(1);
    int i = 0;
    while (1)
    {
        printf("%d\n", i++);
    }
    return 0;
}