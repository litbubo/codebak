#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <signal.h>
#define FIFO "fifo"

void working(int s)
{
    fprintf(stdout,"信号来了\n");
}

int main(int argc, char **argv)
{
    //signal(SIGINT, working);
    struct sigaction sig;
    sig.sa_handler = working;
    sig.sa_flags = 0;
    sig.sa_flags |= SA_INTERRUPT;
    //sigemptyset(&sig.sa_mask);
    //sig.sa_flags |= SA_RESTART;
    sigfillset(&sig.sa_mask);
    sigaction(SIGINT, &sig, NULL);
    int fd = open(FIFO, O_RDONLY);
    if (fd < 0)
    {
        perror("open");
        exit(1);
    }
    //int fd_flags = fcntl(fd, F_GETFL);
    //fcntl(fd, F_SETFL, fd_flags | O_NONBLOCK);
    write(STDOUT_FILENO, "open fifo success\n", sizeof("open fifo success\n"));

    char buf[1024];
    memset(buf, 0, sizeof(buf));

    while (1)
    {
        int len = read(fd, buf, sizeof(buf));
        printf("%d\n", len);
        if (len == 0)
        {
            write(STDOUT_FILENO, "end\n", 4);
            break;
        }
        //else if(len < 0 && errno == EAGAIN)
        else if(len < 0)
        {
            if(errno == EINTR)
            {
                fprintf(stderr, "EINTR is called! %s\n", strerror(errno));
                continue;
            }
            perror("read failed !");
            break;
        }
        else{

            write(STDOUT_FILENO, buf, len);
        }
    }
    close(fd);
    unlink(FIFO);

    exit(0);
}
