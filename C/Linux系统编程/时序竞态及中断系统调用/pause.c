#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
#include <signal.h>
#include <string.h>
typedef void (*sighandler_t)(int);

void working_int(int s)
{
    fprintf(stdout, "int 信号来了前\n");
    sleep(5);
    fprintf(stdout, "int 信号来了后\n");
}

void working_count(int s)
{
    int i;
    static int sum = 0;
    for(i = 0; i < 5; i++)
    {
        sleep(1);
        sum += i;
    }
    printf("%d\n", sum);
    sum = 0;
}

void working_qiut(int s)
{
    fprintf(stdout, "qiut 信号来了前\n");
    sleep(5);
    fprintf(stdout, "qiut 信号来了后\n");
}

int main()
{

    struct sigaction sig;
    sig.sa_handler = working_int;
    sig.sa_flags = 0;
    //sigemptyset(&sig.sa_mask);
    sigfillset(&sig.sa_mask);
    sigaction(SIGINT, &sig, NULL);

    sig.sa_handler = working_qiut;
    sig.sa_flags = 0;
    //sigemptyset(&sig.sa_mask);
    sigfillset(&sig.sa_mask);
    sigaction(SIGQUIT, &sig, NULL);



    //signal(SIGINT, working_count);
    // while(1)
    //{
    sleep(2);
    int ret;
    while(1)
    {
        ret = pause();
        if(ret == -1)
        {
            if(errno == EINTR)
            {
                fprintf(stderr, "ENITR is called! %s\n", strerror(errno));
                continue;
            }
            break;
        }
    }
    //}

    printf("Hello world\n");
    return 0;
}

