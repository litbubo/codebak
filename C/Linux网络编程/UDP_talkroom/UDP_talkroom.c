#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <arpa/inet.h>
#include <net/if.h>
#include <pthread.h>

#define SERVER_PORT 9000
#define CLIENT_PORT 9000
#define MAXLINE 1500

#define GROUP "239.0.0.2"

int sockfd;

void *work(void *arg)
{
    while (1)
    {
        char buf[BUFSIZ];
        memset(buf, 0, sizeof(buf));
        int len = recvfrom(sockfd, buf, sizeof(buf), 0, NULL, 0);
        printf("recv message:\n");
        write(STDOUT_FILENO, buf, len);
    }
    pthread_exit(NULL);
}

int main(void)
{
    struct sockaddr_in serveraddr, clientaddr;
    char buf[MAXLINE];
    struct ip_mreqn group;

    sockfd = socket(AF_INET, SOCK_DGRAM, 0); /* 构造用于UDP通信的套接字 */

    bzero(&serveraddr, sizeof(serveraddr));
    serveraddr.sin_family = AF_INET;                /* IPv4 */
    serveraddr.sin_addr.s_addr = htonl(INADDR_ANY); /* 本地任意IP INADDR_ANY = 0 */
    serveraddr.sin_port = htons(SERVER_PORT);
    bind(sockfd, (struct sockaddr *)&serveraddr, sizeof(serveraddr));

    inet_pton(AF_INET, GROUP, &group.imr_multiaddr);                          /* 设置组地址 */
    inet_pton(AF_INET, "0.0.0.0", &group.imr_address);                        /* 本地任意IP */
    group.imr_ifindex = if_nametoindex("ens33");                              /* 给出网卡名,转换为对应编号: eth0 --> 编号  命令:ip ad */
    setsockopt(sockfd, IPPROTO_IP, IP_MULTICAST_IF, &group, sizeof(group));   /* 组播权限 */
    setsockopt(sockfd, IPPROTO_IP, IP_ADD_MEMBERSHIP, &group, sizeof(group)); /* 设置client 加入多播组 */

    int val = 0;
    setsockopt(sockfd, IPPROTO_IP, IP_MULTICAST_LOOP, &(val), sizeof(val));

    pthread_t tid;
    pthread_create(&tid, NULL, work, NULL);
    pthread_detach(tid);

    bzero(&clientaddr, sizeof(clientaddr)); /* 构造 client 地址 IP+端口 */
    clientaddr.sin_family = AF_INET;
    inet_pton(AF_INET, GROUP, &clientaddr.sin_addr.s_addr); /* IPv4  239.0.0.2+9000 */
    clientaddr.sin_port = htons(CLIENT_PORT);
    while (1)
    {
        printf("input your messages:\n");
        fgets(buf, sizeof(buf), stdin);
        sendto(sockfd, buf, strlen(buf), 0, (struct sockaddr *)&clientaddr, sizeof(clientaddr));
    }

    close(sockfd);

    return 0;
}
