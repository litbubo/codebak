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
    addr.sin_port = htons(30002);
    inet_pton(AF_INET, "127.0.0.1", &addr.sin_addr.s_addr);

    while (fgets(inputBuffer, sizeof(inputBuffer), stdin) != NULL)
    {
        int len = sendto(sfd, inputBuffer, sizeof(inputBuffer), 0, (struct sockaddr *)&addr, sizeof(addr));
        printf("%d\n",len );
        if(len < 0)
            perror("sendto");
        recvfrom(sfd, buf, sizeof(buf), 0, NULL, 0);
        write(STDOUT_FILENO, buf, sizeof(buf));
    }
}