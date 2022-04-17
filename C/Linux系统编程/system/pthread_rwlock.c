#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/time.h>
#include <unistd.h>
#include <errno.h>
#include <sys/mman.h>
#include <sys/wait.h>
#include <pthread.h>

int count = 0;
pthread_rwlock_t rwlock;

void *read_pthread(void *arg)
{
    // int t = count;
    int i = (int)arg;
    while (1)
    {
        usleep(500);
        pthread_rwlock_rdlock(&rwlock);
        printf("read thread %dth, count == %d\n", i, count);
        pthread_rwlock_unlock(&rwlock);
    }
}

void *write_pthread(void *arg)
{
    // int t = count;
    int i = (int)arg;
    while (1)
    {
        usleep(900);
        pthread_rwlock_wrlock(&rwlock);
        printf("write thread %dth, count is going to == %d\n", i, ++count);
        pthread_rwlock_unlock(&rwlock);
    }
}

int main(int argc, char **argv)
{
    pthread_rwlock_init(&rwlock, NULL);
    pthread_t thread[8];
    for (int i = 0; i < 3; i++)
    {
        pthread_create(&thread[i], NULL, write_pthread, (void *)i);
    }
    for (int i = 0; i < 5; i++)
    {
        pthread_create(&thread[i + 3], NULL, read_pthread, (void *)i);
    }
    for (int i = 0; i < 8; i++)
    {
        pthread_join(thread[i], NULL);
    }
    pthread_rwlock_destroy(&rwlock);
    return 0;
}