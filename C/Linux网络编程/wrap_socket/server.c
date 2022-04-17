#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/stat.h>
#include <ctype.h>
#include <arpa/inet.h>
#include <fcntl.h>

#include "wrap.h"

int main(int argc, char **argv)
{
    int sfd, cfd;
    struct sockaddr_in sock, clientsock;
    socklen_t len;
    char buf[BUFSIZ], clientIP[BUFSIZ];

    sfd = Socket(AF_INET, SOCK_STREAM, 0);

    bzero(&sock, sizeof(struct sockaddr_in));
    sock.sin_family = AF_INET;
    sock.sin_addr.s_addr = htonl(INADDR_ANY);
    sock.sin_port = htons(30001);
    Bind(sfd, (struct sockaddr *)&sock, sizeof(sock));

    Listen(sfd, 128);

    len = sizeof(clientsock);
    cfd = Accept(sfd, (struct sockaddr *)&clientsock, &len);

    printf("CLIENT IP = %s, PORT = %d\n", inet_ntop(AF_INET, &clientsock.sin_addr.s_addr, clientIP, sizeof(clientIP)),
           ntohs(clientsock.sin_port));
    while (1)
    {
        int buflen = Read(cfd, buf, sizeof(buf));
        Write(STDOUT_FILENO, buf, buflen);
        for (int i = 0; i < buflen; i++)
        {
            buf[i] = toupper(buf[i]);
        }
        Write(cfd, buf, buflen);
    }
    Close(cfd);
    Close(sfd);
    return 0;
}