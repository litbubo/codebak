#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
/*
void *working(void *arg)
{
    int sum = 0;
    for (int i = 0; i < 10; i++)
    {
        sum += i;
    }
    printf("sum == %d\n", sum);
    for(int i = 0; ; i++)
    {
        printf("child = %d\n", i);
    }
    return NULL;
}
*/
void *working(void *arg)
{
    while(1)
    {
        pthread_testcancel();
    }
}

int main(int argc, char **argv)
{
    pthread_t thread;
    pthread_create(&thread, NULL, working, NULL);
    printf("child create ID = %ld\n", thread);
    printf("main ID = %ld\n", pthread_self());

    pthread_detach(thread);
    pthread_cancel(thread);
    pthread_exit(NULL);
    return 0;
}