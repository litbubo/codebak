#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/time.h>
#include <unistd.h>

void print_pending(const sigset_t *set)
{
    for (int i = 0; i < 32; i++)
    {
        if (sigismember(set, i) == 1)
            putchar('1');
        else
            putchar('0');
    }
    printf("\n");
}

int main(int argc, char **argv)
{
    sigset_t ped, oldset, newset;
    sigemptyset(&newset);
    sigaddset(&newset, SIGQUIT);
    sigaddset(&newset, SIGINT);

    sigprocmask(SIG_BLOCK, &newset, &oldset);


    while (1)
    {
        sigpending(&ped);
        print_pending(&ped);
        sleep(1);
    }
}