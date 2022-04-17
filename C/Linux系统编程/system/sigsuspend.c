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
    sigset_t newmask, oldmask, suspendmask;
    struct sigaction newaction, oldaction;
    
    newaction.sa_handler = signal_catch;
    newaction.sa_flags = 0;
    sigemptyset(&newaction.sa_mask);
    ret = sigaction(SIGALRM, &newaction, &oldaction);
    if (ret == -1)
    {
        perror("sigaction");
        exit(1);
    }

    sigemptyset(&newmask);
    sigaddset(&newmask, SIGALRM);
    ret = sigprocmask(SIG_BLOCK, &newmask, &oldmask);
    if (ret == -1)
    {
        perror("sigprocmask");
        exit(1);
    }
    suspendmask = oldmask;
    sigdelset(&suspendmask, SIGALRM);

    alarm(seconds);
    ret = sigsuspend(&suspendmask);
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

    ret = sigprocmask(SIG_SETMASK, &oldmask, NULL);
    if (ret == -1)
    {
        perror("sigprocmask");
        exit(1);
    }
    return retsec;
}

int main(int argc, char **argv)
{
    mysleep(3);
    printf("----------\n");
    alarm(2);
    while (1)
        ;
    return 0;
}