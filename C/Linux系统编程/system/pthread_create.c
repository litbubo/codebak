#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#include <stdlib.h>

struct person
{
    int id;
    int age;
};

void *callback(void *arg)
{
    for (size_t i = 0; i < 5; i++)
    {
        printf("child printf %ld\n", i);
    }
    printf("child thread ID = %ld\n", pthread_self());
    //struct person p;
    struct person *p = (struct person *)arg;
    p->id = 111;
    p->age = 10;
    sleep(3);
    pthread_exit(p);
    return NULL;
}

int main(int argc, char **argv)
{
    pthread_t thread;
    struct person p;
    pthread_create(&thread, NULL, callback, &p);
    /*
    for (size_t i = 0; i < 5; i++)
    {
        printf("main printf %ld\n", i);
    }*/
    printf("main thread ID = %ld\n", pthread_self());
    //void *arg = NULL;
    //pthread_exit(NULL);
    //pthread_join(thread, &arg);
    //struct person *p = (struct person *)arg;
    pthread_detach(thread);
    printf("id == %d, age == %d\n", p.id, p.age);
    pthread_exit(NULL);
    return 0;
}