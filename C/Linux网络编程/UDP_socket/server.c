#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <ctype.h>

int main(int argc, char **argv)
{
    int sfd = socket(AF_INET, SOCK_DGRAM, 0);
    char buf[BUFSIZ], clientIP[INET_ADDRSTRLEN];

    struct sockaddr_in caddr, saddr;

    bzero(&caddr, sizeof(caddr));
    bzero(&saddr, sizeof(saddr));

    saddr.sin_family = AF_INET;
    saddr.sin_port = htons(30002);
    saddr.sin_addr.s_addr = htonl(INADDR_ANY);

    bind(sfd, (struct sockaddr *)&saddr, sizeof(saddr));
    printf("wait message ....\n");

    socklen_t socklen = sizeof(caddr);
    
    while (1)
    {
        ssize_t len = recvfrom(sfd, buf, sizeof(buf), 0, (struct sockaddr *)&caddr, &socklen);
        printf("recv message from %s and port %d\n",
               inet_ntop(AF_INET, &caddr.sin_addr.s_addr, clientIP, sizeof(clientIP)),
               ntohs(caddr.sin_port));
        for (int i = 0; i < len; i++)
        {
            buf[i] = toupper(buf[i]);
        }
        write(STDOUT_FILENO, buf, len);
        sendto(sfd, buf, len, 0, (struct sockaddr *)&caddr, sizeof(caddr));
    }
    close(sfd);
    return 0;
}