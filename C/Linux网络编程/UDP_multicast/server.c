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
    int sfd = socket(AF_INET, SOCK_DGRAM, 0);
    char buf[BUFSIZ], clientIP[INET_ADDRSTRLEN];

    struct sockaddr_in caddr, saddr;
    struct ip_mreqn group;

    bzero(&caddr, sizeof(caddr));
    bzero(&saddr, sizeof(saddr));

    saddr.sin_family = AF_INET;
    saddr.sin_port = htons(30006);
    saddr.sin_addr.s_addr = htonl(INADDR_ANY);

    bind(sfd, (struct sockaddr *)&saddr, sizeof(saddr));

    inet_pton(AF_INET,"0.0.0.0", &group.imr_address);
    inet_pton(AF_INET, "239.0.0.2", &group.imr_multiaddr);
    group.imr_ifindex = if_nametoindex("ens33");

    setsockopt(sfd, IPPROTO_IP, IP_MULTICAST_IF, &group, sizeof(group));  /* 组播权限 */
    printf("wait message ....\n");

    caddr.sin_family = AF_INET;
    caddr.sin_port = htons(30007);
    inet_pton(AF_INET, "239.0.0.2", &caddr.sin_addr.s_addr);

    socklen_t socklen = sizeof(caddr);
    int i = 0;
    while (1)
    {
        sprintf(buf, "this is %dth multicast message\n", i++);
        int len = sendto(sfd, buf, strlen(buf), 0, (struct sockaddr *)&caddr, sizeof(caddr));
        printf("%d\n", len);
        sleep(1);
    }
    close(sfd);
    return 0;
}