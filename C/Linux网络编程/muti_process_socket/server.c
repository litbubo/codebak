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

#include "wrap.h"

void reclcyle(int signal)
{
    int ret;
    while ((ret = waitpid(0, NULL, WNOHANG)) > 0)
    {
        printf("回收成功\n");
    }
    return;
}

int main(int argc, char **argv)
{
    int sfd, cfd;
    pid_t pid;
    struct sockaddr_in saddr, caddr;
    socklen_t addrlen;
    char ClientIP[BUFSIZ], buf[BUFSIZ];
    addrlen = sizeof(caddr);
    sfd = Socket(AF_INET, SOCK_STREAM, 0);
    memset(&caddr, 0, sizeof(caddr));
    memset(&saddr, 0, sizeof(saddr));
    saddr.sin_family = AF_INET;
    saddr.sin_addr.s_addr = htonl(INADDR_ANY);
    saddr.sin_port = htons(30001);
    Bind(sfd, (struct sockaddr *)&saddr, sizeof(saddr));
    Listen(sfd, 128);

    struct sigaction sa;
    sa.sa_flags = 0;
    sa.sa_handler = reclcyle;
    sigemptyset(&sa.sa_mask);

    while (1)
    {
        cfd = Accept(sfd, (struct sockaddr *)&caddr, &addrlen);
        printf("Client IP == %s,Client Port == %d\n",
               inet_ntop(AF_INET, &caddr.sin_addr.s_addr, ClientIP, sizeof(ClientIP)),
               ntohs(caddr.sin_port));
        pid = fork();
        if (pid < 0)
        {
            perror("fork");
            exit(1);
        }
        else if (pid == 0)
        {
            Close(sfd);
            break;
        }
        else
        {
            Close(cfd);
            sigaction(SIGCHLD, &sa, NULL);
        }
    }

    if (pid == 0)
    {
        while (1)
        {

            ssize_t ret = Read(cfd, buf, sizeof(buf));
            if (ret == -1)
            {
                Close(cfd);
                return -1;
            }
            else if (ret == 0)
            {
                printf("客户端已关闭, cfd == %d\n", cfd);
                break;
            }
            Write(STDOUT_FILENO, buf, ret);
            for (int i = 0; i < ret; i++)
            {
                buf[i] = toupper(buf[i]);
            }
            Write(cfd, buf, ret);
        }
        Close(cfd);
        return 0;
    }
    Close(sfd);
    return 0;
}