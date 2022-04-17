#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#include <stdlib.h>
#include <errno.h>

pthread_mutex_t mutex;

void *work(void *arg)
{
    srand(time(NULL));
    while (1)
    {
        pthread_mutex_lock(&mutex);
        printf("hello ");
        sleep(rand() % 3);
        printf("world\n");
        pthread_mutex_unlock(&mutex);
        sleep(rand() % 3);
    }
}

int main(int argc, char **argv)
{
    pthread_t thread;
    srand(time(NULL));
    pthread_mutex_init(&mutex, NULL);
    pthread_create(&thread, NULL, work, NULL);
    while (1)
    {
        pthread_mutex_lock(&mutex);
        printf("HELLO ");
        sleep(rand() % 3);
        printf("WORLD\n");
        pthread_mutex_unlock(&mutex);
        sleep(rand() % 3);
    }
    pthread_mutex_destroy(&mutex);
}