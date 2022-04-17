#include <stdio.h>
#include <stdlib.h>
#include <sys/epoll.h>
#include <errno.h>
#include <unistd.h>

#define MAXLINE 10

int main(int argc, char **argv)
{
    pid_t pid;
    int fd[2];
    pipe(fd);
    char buf[MAXLINE];
    char recvbuf[MAXLINE / 2];
    

    pid = fork();
    if (pid < 0)
    {
        perror("fork");
        exit(1);
    }
    else if (pid == 0)
    {
        char c = 'A';
        int i;
        close(fd[0]);
        while (1)
        {
            for (i = 0; i < MAXLINE / 2; i++)
            {
                buf[i] = c;
            }
            buf[i - 1] = '\n';
            c++;
            for (; i < MAXLINE; i++)
            {
                buf[i] = c;
            }
            buf[i - 1] = '\n';
            c++;
            write(fd[1], buf, MAXLINE);
            sleep(3);
        }
    }
    else
    {
        close(fd[1]);
        int epfd = epoll_create(10);
        struct epoll_event event, evts[2];
        event.data.fd = fd[0];
        event.events = EPOLLIN;
        //event.events = EPOLLIN | EPOLLET;
        epoll_ctl(epfd, EPOLL_CTL_ADD, fd[0], &event);

        while (1)
        {
            int nready = epoll_wait(epfd, evts, 10, -1);
            if(nready > 0)
            {
                int len = read(fd[0], recvbuf, 3);
                write(STDOUT_FILENO, recvbuf, len);
            }
        }
    }
}