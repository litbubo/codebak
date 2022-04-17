#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <sys/wait.h>
#include <sys/select.h>
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
    int i, maxi;
    int sfd, cfd;
    struct sockaddr_in saddr, caddr;
    socklen_t addrlen;
    char ClientIP[INET_ADDRSTRLEN], buf[BUFSIZ];
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

    struct pollfd clientPoll[OPENMAX];
    for (i = 0; i < OPENMAX; i++)
    {
        clientPoll[i].fd = -1;
        clientPoll[i].events = 0;
        clientPoll[i].revents = 0;
    }

    clientPoll[0].fd = sfd;
    clientPoll[0].events = POLLIN;
    maxi = 0;

    while (1)
    {

        int nready = poll(clientPoll, maxi + 1, -1);
        if (nready < 0)
        {
                perr_exit("poll");
        }
        else if (nready > 0)
        {
            if ((clientPoll[0].revents & POLLIN) == 1)
            {
                cfd = Accept(clientPoll[0].fd, (struct sockaddr *)&caddr, &addrlen);
                printf("Client IP == %s, Client Port == %d\n",
                       inet_ntop(AF_INET, &caddr.sin_addr.s_addr, ClientIP, sizeof(ClientIP)),
                       ntohs(caddr.sin_port));
                for (i = 0; i < OPENMAX; i++)
                    if (clientPoll[i].fd < 0)
                    {
                        clientPoll[i].fd = cfd;
                        break;
                    }
                if (i == OPENMAX)
                {
                    printf("没有更多的描述符了\n");
                    exit(1);
                }
                clientPoll[i].events = POLLIN;
                if (i > maxi)
                    maxi = i;
                if (--nready <= 0)
                    continue;
            }

            for (i = 1; i <= maxi; i++)
            {
                int len;
                if (clientPoll[i].fd < 0)
                    continue;
                else if ((clientPoll[i].revents & POLLIN) == 1)
                {
                    if ((len = Read(clientPoll[i].fd, buf, sizeof(buf))) == 0)
                    {
                        printf("客户端断开了连接， fd == %d\n", clientPoll[i].fd);
                        Close(clientPoll[i].fd);
                        clientPoll[i].fd = -1;
                    }
                    else if (len > 0)
                    {
                        for (int j = 0; j < len; j++)
                        {
                            buf[j] = toupper(buf[j]);
                        }
                        Write(clientPoll[i].fd, buf, len);
                        Write(STDOUT_FILENO, buf, len);
                    }
                    if (--nready <= 0)
                        break;
                }
            }
        }
    }

    return 0;
}