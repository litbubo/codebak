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

#include "wrap.h"

int main(int argc, char **argv)
{
    int i, maxi;
    int sfd, cfd, maxfd;
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

    int fdClient[FD_SETSIZE];
    fd_set rdset, allset;
    FD_ZERO(&allset);
    FD_SET(sfd, &allset);
    maxfd = sfd;
    maxi = -1;
    for (i = 0; i < FD_SETSIZE; i++)
    {
        fdClient[i] = -1;
    }

    while (1)
    {
        rdset = allset;
        int nready = select(maxfd + 1, &rdset, NULL, NULL, NULL);
        if (nready < 0)
            perr_exit("select");
        else if (nready > 0)
        {
            if (FD_ISSET(sfd, &rdset) == 1)
            {
                cfd = Accept(sfd, (struct sockaddr *)&caddr, &addrlen);
                printf("Client IP == %s, Client Port == %d\n",
                       inet_ntop(AF_INET, &caddr.sin_addr.s_addr, ClientIP, sizeof(ClientIP)),
                       ntohs(caddr.sin_port));
                for (i = 0; i < FD_SETSIZE; i++)
                    if (fdClient[i] < 0)
                    {
                        fdClient[i] = cfd;
                        break;
                    }
                if (i == FD_SETSIZE)
                {
                    printf("没有更多的描述符了\n");
                    exit(1);
                }
                if (i > maxi)
                    maxi = i;
                if (cfd > sfd)
                    maxfd = cfd;
                FD_SET(cfd, &allset);
                if (--nready == 0)
                    continue;
            }

            for (i = 0; i <= maxi; i++)
            {
                printf("i == %d\n", i);
                int socktemp = fdClient[i];
                int len;
                if (socktemp < 0)
                    continue;
                else if (FD_ISSET(socktemp, &rdset) == 1)
                {
                    if ((len = Read(socktemp, buf, sizeof(buf))) == 0)
                    {
                        printf("客户端断开了连接， fd == %d\n", socktemp);
                        FD_CLR(socktemp, &allset);
                        Close(socktemp);
                        fdClient[i] = -1;
                    }
                    else if (len > 0)
                    {
                        for (int j = 0; j < len; j++)
                        {
                            buf[j] = toupper(buf[j]);
                        }
                        Write(socktemp, buf, len);
                        Write(STDOUT_FILENO, buf, len);
                    }
                    if (--nready == 0)
                        break;
                }
            }
        }
    }

    return 0;
}