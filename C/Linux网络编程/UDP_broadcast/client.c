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
    char inputBuffer[BUFSIZ];
    char buf[BUFSIZ];
    int sfd = socket(AF_INET, SOCK_DGRAM, 0);

    struct sockaddr_in addr;
    bzero(&addr, sizeof(addr));

    addr.sin_family = AF_INET;
    addr.sin_port = htons(30004);
    inet_pton(AF_INET,"0.0.0.0", &addr.sin_addr.s_addr);
    bind(sfd, (struct sockaddr *)&addr, sizeof(addr));

    while (1)
    {
        int len = recvfrom(sfd, buf, sizeof(buf), 0, NULL, 0);
        write(STDOUT_FILENO, buf, len);
    }
}