#include <stdio.h>
#include <unistd.h>
#include <sys/socket.h>
#include <strings.h>
#include <string.h>
#include <ctype.h>
#include <arpa/inet.h>
#include <sys/un.h>
#include <stddef.h>

#define SEVR_ADDR "serv.socket"
#define CLIT_ADDR "clit.socket"
#include "wrap.h"

int main(int argc, char **argv)
{
    char buf[BUFSIZ];
    int cfd = socket(AF_UNIX, SOCK_STREAM, 0);
    struct sockaddr_un caddr, saddr;
    int len;
    bzero(&caddr, sizeof(caddr));
    bzero(&saddr, sizeof(saddr));

    caddr.sun_family = AF_UNIX;
    strcpy(caddr.sun_path, CLIT_ADDR);

    len = offsetof(struct sockaddr_un, sun_path) + strlen(caddr.sun_path);

    unlink(CLIT_ADDR);
    Bind(cfd, (struct sockaddr *)&caddr, len);

    saddr.sun_family = AF_UNIX;
    strcpy(saddr.sun_path, SEVR_ADDR);
    len = offsetof(struct sockaddr_un, sun_path) + strlen(saddr.sun_path);

    Connect(cfd, (struct sockaddr *)&saddr, len);
    while (1)
    {
        fgets(buf, sizeof(buf), stdin);
        Write(cfd, buf, strlen(buf));
        len = Read(cfd, buf, sizeof(buf));
        write(STDOUT_FILENO, buf, len);
    }
    Close(cfd);
    return 0;
}