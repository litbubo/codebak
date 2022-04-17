#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <pthread.h>
#include <stdlib.h>
#include <semaphore.h>
struct Node
{
    int val;
    struct Node *next;
};
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cond = PTHREAD_COND_INITIALIZER;

sem_t semp;
sem_t semc;

struct Node *head = NULL;
void *producter(void *arg)
{
    while(1)
    {   
        sem_wait(&semp);
        pthread_mutex_lock(&mutex);
        struct Node *p = malloc(sizeof(struct Node));
        p->val = (rand()%100);
        p->next = head;
        head = p;
        printf("[%ld]:product a Node : valude == %d\n", pthread_self(), p->val);
        pthread_mutex_unlock(&mutex);
        //pthread_cond_broadcast(&cond);
        //sleep(rand()%3);
        sem_post(&semc);
        sched_yield();
    }
    pthread_exit(0);
}

void *customer(void *arg)
{
    while(1)
    {
        sem_wait(&semc);
        pthread_mutex_lock(&mutex);
        //while(head == NULL)
        //{
        //    pthread_cond_wait(&cond, &mutex);
        //}
        struct Node *p = head;
        head = p->next;
        printf("[%ld]:customer a Node : valude == %d\n", pthread_self(), p->val);
        free(p);
        p = NULL;
        pthread_mutex_unlock(&mutex);
        sem_post(&semp);
        //sleep(rand()%3);
        sched_yield();
    }
    pthread_exit(0);
}


int main()
{
    int i = 0;
    sem_init(&semc, 0, 0);
    sem_init(&semp, 0, 2);
    pthread_t p_tid[2], c_tid[5];
    for(i = 0; i < 2; i++)
    {
        pthread_create(&p_tid[i], NULL, producter, NULL);
    }
    for(i = 0; i < 5; i++)
    {
        pthread_create(&c_tid[i], NULL, customer, NULL);
    }
    
    //alarm(1);

    pause();
    //sleep(1);

    for(i = 0; i < 2; i++)
    {
        printf("producter is cancel: %d\n", i);
        pthread_cancel(p_tid[i]);
        pthread_join(p_tid[i], NULL);
    }
    for(i = 0; i < 5; i++)
    {
        printf("customer is cancel: %d\n", i);
        pthread_cancel(c_tid[i]);
        pthread_join(c_tid[i], NULL);
    }
    
    pthread_mutex_destroy(&mutex);
    pthread_cond_destroy(&cond);
    sem_destroy(&semc);
    sem_destroy(&semp);
    printf("Hello world\n");
    return 0;
}

