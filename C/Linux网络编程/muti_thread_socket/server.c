#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <sys/wait.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/stat.h>
#include <ctype.h>
#include <arpa/inet.h>
#include <fcntl.h>
#include <signal.h>
#include <pthread.h>

#include "wrap.h"

struct mysock_mess
{
    struct sockaddr_in caddr;
    int cfd;
};

void *dowork(void *arg)
{
    char ClientIP[BUFSIZ], buf[BUFSIZ];
    struct mysock_mess *mess = (struct mysock_mess *)arg;
    printf("Client IP == %s,Client Port == %d\n",
           inet_ntop(AF_INET, &mess->caddr.sin_addr.s_addr, ClientIP, sizeof(ClientIP)),
           ntohs(mess->caddr.sin_port));
    while (1)
    {
        ssize_t ret = Read(mess->cfd, buf, sizeof(buf));
        if (ret == -1)
        {
            exit(1);
        }
        else if (ret == 0)
        {
            printf("客户端已关闭, cfd == %d\n", mess->cfd);
            break;
        }
        Write(STDOUT_FILENO, buf, ret);
        for (int i = 0; i < ret; i++)
        {
            buf[i] = toupper(buf[i]);
        }
        Write(mess->cfd, buf, ret);
    }
    Close(mess->cfd);
    return NULL;
}

int main(int argc, char **argv)
{
    int sfd, cfd;
    int i = 0;
    struct sockaddr_in saddr, caddr;
    socklen_t addrlen;
    struct mysock_mess mess[256];
    memset(mess, 0, sizeof(mess));
    pthread_t thread;

    addrlen = sizeof(caddr);
    sfd = Socket(AF_INET, SOCK_STREAM, 0);
    memset(&caddr, 0, sizeof(caddr));
    memset(&saddr, 0, sizeof(saddr));
    saddr.sin_family = AF_INET;
    saddr.sin_addr.s_addr = htonl(INADDR_ANY);
    saddr.sin_port = htons(30005);
    Bind(sfd, (struct sockaddr *)&saddr, sizeof(saddr));
    Listen(sfd, 128);
    printf("开始监听\n");
    while (1)
    {
        cfd = Accept(sfd, (struct sockaddr *)&caddr, &addrlen);
        mess[i].caddr = caddr;
        mess[i].cfd = cfd;
        pthread_create(&thread, NULL, dowork, (void *)&mess[i]);
        pthread_detach(thread);
        i++;
    }
    Close(sfd);
    return 0;
}