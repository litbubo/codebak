#include <stdio.h>
#include <string.h>
#include <strings.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <netinet/ip.h>

#include "wrap.h"

int main(int argc, char **argv)
{
    int cfd;
    struct sockaddr_in addr;
    cfd = Socket(AF_INET, SOCK_STREAM, 0);

    bzero(&addr, sizeof(addr));
    addr.sin_family = AF_INET;
    inet_pton(AF_INET, "127.0.0.1", &addr.sin_addr.s_addr);
    addr.sin_port = htons(30001);
    Connect(cfd, (struct sockaddr *)&addr, sizeof(addr));

    char buf[BUFSIZ];
    memset(buf, 0, sizeof(buf));
    while (1)
    {
        fgets(buf, sizeof(buf), stdin);
        Write(cfd, buf, strlen(buf));
        int len = Read(cfd, buf, sizeof(buf));
        Write(STDOUT_FILENO, buf, len);
    }

    Close(cfd);
    return 0;
}