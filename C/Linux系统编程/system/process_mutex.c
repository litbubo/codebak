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


struct mystruct
{
    int num;
    pthread_mutex_t mutex;
    pthread_mutexattr_t attr;
};


int main(int argc, char **argv)
{
    int i;
    struct mystruct *my;
    pid_t pid;
    my = mmap(NULL, sizeof(struct mystruct), PROT_READ | PROT_WRITE, MAP_SHARED | MAP_ANON, -1, 0);
    memset(my, 0, sizeof(struct mystruct));

    pthread_mutexattr_init(&(my->attr));
    pthread_mutexattr_setpshared(&(my->attr), PTHREAD_PROCESS_SHARED);   

    pthread_mutex_init(&(my->mutex), &(my->attr));
    srand(time(NULL));
    pid = fork();
    if(pid == 0)
    {
        for(i = 0; i < 10; i++)
        {
            pthread_mutex_lock(&(my->mutex));
            (my->num)++;
            printf("child process ++, i == %d\n", my->num);
            pthread_mutex_unlock(&(my->mutex));
            sleep(rand() % 2);
        }
    }
    else if(pid > 0)
    {
        for(i = 0; i < 10; i++)
        {
            pthread_mutex_lock(&(my->mutex));
            (my->num) += 2;
            printf("parent process +2, i == %d\n", my->num);
            pthread_mutex_unlock(&(my->mutex));
            sleep(rand() % 2);
        }
    }
    wait(NULL);
    pthread_mutexattr_destroy(&(my->attr));
    pthread_mutex_destroy(&(my->mutex));
    munmap(my, sizeof(struct mystruct));
    return 0;
}