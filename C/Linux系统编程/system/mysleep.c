#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/time.h>
#include <unistd.h>
#include <errno.h>

void signal_catch(int signal)
{
    return;
}

unsigned int mysleep(unsigned int seconds)
{
    int ret;
    struct sigaction newaction, oldaction;
    newaction.sa_handler = signal_catch;
    newaction.sa_flags = 0;
    sigemptyset(&newaction.sa_mask);
    ret = sigaction(SIGALRM, &newaction, &oldaction);
    if (ret == -1)
    {
        perror("sigaction");
    }

    alarm(seconds);
    ret = pause();
    if (ret == -1 && errno == EINTR)
    {
        printf("pause succeeded\n");
    }
    int retsec = alarm(0);

    ret = sigaction(SIGALRM, &oldaction, NULL);
    if (ret == -1)
    {
        perror("sigaction");
    }

    return retsec;
}

int main(int argc, char **argv)
{
    mysleep(3);
    printf("----------\n");
    alarm(2);
    while (1);
    return 0;
}