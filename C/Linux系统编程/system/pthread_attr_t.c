#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#include <stdlib.h>
#include <errno.h>

void *callback(void *arg)
{
    pthread_exit((void *)0);
}

int main(int argc, char **argv)
{
    pthread_t thread;
    int ret;
    pthread_attr_t attr;
    pthread_attr_init(&attr);
    pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_DETACHED);
    ret = pthread_create(&thread, &attr, callback, NULL);
    if (ret != 0)
    {
        fprintf(stderr, "pthread_create: %s\n", strerror(errno));
        exit(1);
    }
    pthread_exit(NULL);
    return 0;
}