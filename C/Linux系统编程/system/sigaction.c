#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/time.h>
#include <unistd.h>
void signal_catch(int signal)
{
    printf("%d signal is catched\n", signal);
    while (1);
}

int main(int argc, char **argv)
{
    struct sigaction act;
    act.sa_handler = signal_catch;
    act.sa_flags = 0;
    sigemptyset(&act.sa_mask);
    sigaddset(&act.sa_mask, SIGQUIT);
    int ret = sigaction(SIGINT, &act, NULL);
    while(1);
}