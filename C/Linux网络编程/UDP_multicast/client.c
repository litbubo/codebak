#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <ctype.h>
#include <net/if.h>
int main(int argc, char **argv)
{
    char inputBuffer[BUFSIZ];
    char buf[BUFSIZ];
    int sfd = socket(AF_INET, SOCK_DGRAM, 0);

    struct sockaddr_in addr;
    struct ip_mreqn group;
    bzero(&addr, sizeof(addr));

    addr.sin_family = AF_INET;
    addr.sin_port = htons(30007);
    inet_pton(AF_INET,"0.0.0.0", &addr.sin_addr.s_addr);
    bind(sfd, (struct sockaddr *)&addr, sizeof(addr));

    inet_pton(AF_INET,"0.0.0.0", &group.imr_address);
    inet_pton(AF_INET, "239.0.0.2", &group.imr_multiaddr);
    group.imr_ifindex = if_nametoindex("ens33");

    setsockopt(sfd, IPPROTO_IP, IP_ADD_MEMBERSHIP, &group, sizeof(group));  /* 组播权限 */

    while (1)
    {
        int len = recvfrom(sfd, buf, sizeof(buf), 0, NULL, 0);
        printf("%d\n", len);
        write(STDOUT_FILENO, buf, len);
    }
    close(sfd);
    return 0;
}