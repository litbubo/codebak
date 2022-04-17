#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#include <stdlib.h>
#include <errno.h>
void *working(void *arg)
{
    int i = (int)arg;
    //sleep(i);
    printf("%dth, child thread ID = %ld, process ID = %ld\n", i, pthread_self(), getpid());
    while (1)
    {
        sleep(1);
    };
    return NULL;
}

int main(int argc, char **argv)
{
    pthread_t thread;
    int i;
    for (int i = 0; ; i++)
    {
        int ret = pthread_create(&thread, NULL, working, (void *)i);
        if (ret != 0)
        {
            fprintf(stderr, "pthread_create: %s\n", strerror(errno));
            exit(1);
        }
    }
    sleep(20);
    return 0;
}