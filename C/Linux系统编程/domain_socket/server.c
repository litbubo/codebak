#include <stdio.h>
#include <unistd.h>
#include <sys/socket.h>
#include <strings.h>
#include <string.h>
#include <ctype.h>
#include <arpa/inet.h>
#include <sys/un.h>
#include <stddef.h>

#define SERV_ADDR "serv.socket"

#include "wrap.h"

int main(int argc, char **argv)
{
    int len;
    int cfd;
    char buf[BUFSIZ];
    int sfd = Socket(AF_UNIX, SOCK_STREAM, 0);
    struct sockaddr_un saddr, caddr;
    bzero(&saddr, sizeof(saddr));
    bzero(&caddr, sizeof(caddr));

    saddr.sun_family = AF_UNIX;
    strcpy(saddr.sun_path, SERV_ADDR);
    len = offsetof(struct sockaddr_un, sun_path) + strlen(saddr.sun_path);
    unlink(SERV_ADDR);
    Bind(sfd, (struct sockaddr *)&saddr, len);

    Listen(sfd, 128);

    printf("wait ....\n");
    len = sizeof(caddr);
    cfd = Accept(sfd, (struct sockaddr *)&caddr, &len);
    len -= offsetof(struct sockaddr_un, sun_path);
    caddr.sun_path[len] = '\0';
    printf("client path == %s\n", caddr.sun_path);

    while (1)
    {
        len = Read(cfd, buf, sizeof(buf));
        for (int i = 0; i < len; i++)
        {
            buf[i] = toupper(buf[i]);
        }
        Write(STDOUT_FILENO, buf, len);
        Write(cfd, buf, len);
    }
    Close(cfd);
    Close(sfd);
    return 0;
}