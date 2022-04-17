#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#include <stdlib.h>
#include <errno.h>

struct my_food
{
    int num;
    struct my_food *next;
};

struct my_food *head = NULL;
struct my_food *mp = NULL;

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cond = PTHREAD_COND_INITIALIZER;

void *product(void *arg)
{
    srand(time(NULL));
    while (1)
    {
        pthread_mutex_lock(&mutex);
        mp = (struct my_food *)malloc(sizeof(struct my_food));
        mp->num = (rand() % 1000 + 1);
        //pthread_mutex_lock(&mutex);
        mp->next = head;
        head = mp;
        printf("product a food %d\n", mp->num);
        pthread_mutex_unlock(&mutex);
        pthread_cond_signal(&cond);
        //sleep(rand() % 2 + 1);
    }
    return NULL;
}

void *customer(void *arg)
{
    srand(time(NULL));
    while (1)
    {
        pthread_mutex_lock(&mutex);
        while (head == NULL)
        {
            pthread_cond_wait(&cond, &mutex);
        }
        mp = head;
        head = mp->next;
        printf("customer eat food %d\n", mp->num);
        free(mp);
        mp = NULL;
        pthread_mutex_unlock(&mutex);
        //sleep(rand() % 2 + 1);
    }
    return NULL;
}

int main(int argc, char **argv)
{
    pthread_t pid, cid;
    pthread_create(&pid, NULL, product, NULL);
    pthread_create(&cid, NULL, customer, NULL);

    pthread_join(pid, NULL);
    pthread_join(cid, NULL);
    return 0;
}