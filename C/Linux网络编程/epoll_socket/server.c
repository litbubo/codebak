#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <sys/wait.h>
#include <sys/select.h>
#include <sys/epoll.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/stat.h>
#include <ctype.h>
#include <arpa/inet.h>
#include <fcntl.h>
#include <signal.h>
#include <poll.h>

#include "wrap.h"

#define OPENMAX 1024

int main(int argc, char **argv)
{
    int i, ret;
    int sfd, cfd;
    struct sockaddr_in saddr, caddr;
    socklen_t addrlen;
    char ClientIP[INET_ADDRSTRLEN], buf[10];
    addrlen = sizeof(caddr);

    sfd = Socket(AF_INET, SOCK_STREAM, 0);

    int opt = 1;
    setsockopt(sfd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));

    memset(&caddr, 0, sizeof(caddr));
    memset(&saddr, 0, sizeof(saddr));
    saddr.sin_family = AF_INET;
    saddr.sin_addr.s_addr = htonl(INADDR_ANY);
    saddr.sin_port = htons(30001);
    Bind(sfd, (struct sockaddr *)&saddr, sizeof(saddr));

    Listen(sfd, 128);

    struct epoll_event evt, evts[OPENMAX];
    int epfd = epoll_create(OPENMAX);
    if (epfd == -1)
        perror("epoll_create");
    evt.events = EPOLLIN;
    // evt.events = EPOLLIN | EPOLLET;
    evt.data.fd = sfd;
    ret = epoll_ctl(epfd, EPOLL_CTL_ADD, sfd, &evt);
    if (ret == -1)
        perror("epoll_ctl");

    while (1)
    {
        int nready = epoll_wait(epfd, evts, OPENMAX, -1);
        if (nready < 0)
        {
            perr_exit("epoll_wait");
        }
        for (i = 0; i < nready; i++)
        {
            if ((!(evts[i].events & EPOLLIN)) == 1)
                continue;
            if (evts[i].data.fd == sfd)
            {
                cfd = Accept(sfd, (struct sockaddr *)&caddr, &addrlen);
                printf("Client IP == %s, Client Port == %d\n",
                       inet_ntop(AF_INET, &caddr.sin_addr.s_addr, ClientIP, sizeof(ClientIP)),
                       ntohs(caddr.sin_port));
                evt.events = EPOLLIN | EPOLLET; // 边沿触发
                // evt.events = EPOLLIN;
                evt.data.fd = cfd;
                epoll_ctl(epfd, EPOLL_CTL_ADD, cfd, &evt);
            }
            else
            {
                int len;
                int sockfd = evts[i].data.fd;

                int flag = fcntl(sockfd, F_GETFL); /* 修改sockfd为非阻塞读 */
                flag |= O_NONBLOCK;
                fcntl(sockfd, F_SETFL, flag);
                while (1)
                {
                    len = Read(sockfd, buf, sizeof(buf));
                    if (len == 0)
                    {
                        printf("客户端断开了连接， fd == %d\n", sockfd);
                        epoll_ctl(epfd, EPOLL_CTL_DEL, sockfd, NULL);
                        Close(sockfd);
                        break;
                    }
                    else if (len > 0)
                    {
                        for (int j = 0; j < len; j++)
                        {
                            buf[j] = toupper(buf[j]);
                        }
                        Write(sockfd, buf, len);
                        Write(STDOUT_FILENO, buf, len);
                    }
                    else
                    {
                        break;
                    }
                }

                /*
                if ((len = Read(sockfd, buf, sizeof(buf))) == 0)
                {
                    printf("客户端断开了连接， fd == %d\n", sockfd);
                    epoll_ctl(epfd, EPOLL_CTL_DEL, sockfd, NULL);
                    Close(sockfd);
                }
                else if (len < 0)
                {
                    perror("read");
                    epoll_ctl(epfd, EPOLL_CTL_DEL, sockfd, NULL);
                    Close(sockfd);
                }
                else
                {
                    for (int j = 0; j < len; j++)
                    {
                        buf[j] = toupper(buf[j]);
                    }
                    Write(sockfd, buf, len);
                    Write(STDOUT_FILENO, buf, len);
                }
                */
            }
        }
    }
    return 0;
}