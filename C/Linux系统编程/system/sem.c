#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#include <stdlib.h>
#include <errno.h>
#include <semaphore.h>
#define NUM 5

int queue[5];

sem_t sem_blank, sem_star;

void *product(void *arg)
{
    srand(time(NULL));
    int i = 0;
    while (1)
    {
        sem_wait(&sem_blank);
        queue[i] = rand() % 1000 + 1;
        printf("produce star = %d\n", queue[i]);
        sem_post(&sem_star);
        i = (i + 1) % NUM;
        //sleep(rand() % 2);
    }
    return NULL;
}

void *customer(void *arg)
{
    srand(time(NULL));
    int i = 0;
    while (1)
    {
        sem_wait(&sem_star);
        printf("customer star = %d\n", queue[i]);
        queue[i] = 0;
        sem_post(&sem_blank);
        i = (i + 1) % NUM;
        //sleep(rand() % 2);
    }
    return NULL;
}

int main(int argc, char **argv)
{
    pthread_t ptid, ctid;
    sem_init(&sem_blank, 0, NUM);
    sem_init(&sem_star, 0, 0);
    pthread_create(&ptid, NULL, product, NULL);
    pthread_create(&ctid, NULL, customer, NULL);

    pthread_join(ptid, NULL);
    pthread_join(ctid, NULL);
    return 0;
}