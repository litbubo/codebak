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
    saddr.sin_port = htons(30003);
    saddr.sin_addr.s_addr = htonl(INADDR_ANY);

    int flag = 1;
    setsockopt(sfd, SOL_SOCKET, SO_BROADCAST, &flag, sizeof(flag));

    bind(sfd, (struct sockaddr *)&saddr, sizeof(saddr));
    printf("wait message ....\n");

    caddr.sin_family = AF_INET;
    caddr.sin_port = htons(30004);
    inet_pton(AF_INET, "192.168.0.255", &caddr.sin_addr.s_addr);

    socklen_t socklen = sizeof(caddr);
    int i = 0;
    while (1)
    {
        sprintf(buf, "this is %dth message\n", i++);
        sendto(sfd, buf, strlen(buf), 0, (struct sockaddr *)&caddr, sizeof(caddr));
        sleep(1);
    }
    close(sfd);
    return 0;
}