#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/time.h>
#include <unistd.h>

typedef void (*sighandler_t)(int);

void myHelloWorld(int signal)
{
    printf("Hello %d\n", signal);
}

void my_alarm(unsigned int timeout)
{
    sighandler_t sigret;
    sigret = signal(SIGALRM, myHelloWorld);
    if(sigret == SIG_ERR)
    {
        perror("signal");
        exit(1);
    }
    struct itimerval oldit, newit;
    newit.it_interval.tv_sec = 1;
    newit.it_interval.tv_usec = 0;
    newit.it_value.tv_sec = timeout;
    newit.it_value.tv_usec = 0;

    int ret = setitimer(ITIMER_REAL, &newit, &oldit);
    if (ret == -1)
    {
        perror("setitimer");
        exit(1);
    }
}

int main(int argc, char **argv)
{
    my_alarm(5);
    int i = 0;
    while (1)
    {
    //    printf("%d\n", i++);
    }
    return 0;
}