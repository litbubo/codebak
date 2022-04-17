#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>

struct Person
{
    int sno;
    int grade;
};

void *working(void* arg)
{
    struct Person *p = (struct Person *)arg;

    p->grade = 99;
    p->sno = 11;

    return NULL;
}



int main()
{
    pthread_t tid;

    struct Person p;
    pthread_create(&tid, NULL, working, &p);

    pthread_join(tid, NULL);
    printf("sno == %d, grade == %d\n", p.sno, p.grade);
    
    
    return 0;
}

