#include "wrap.h"

void perr_exit(char *err)
{
    perror(err);
    exit(1);
}

int Socket(int domain, int type, int protocol)
{
    int ret = socket(domain, type, protocol);
    if (ret < 0)
    {
        perr_exit("socket");
    }
    return ret;
}

int Bind(int sockfd, const struct sockaddr *addr, socklen_t addrlen)
{
    int ret = bind(sockfd, addr, addrlen);
    if (ret < 0)
    {
        perr_exit("bind");
    }
    return ret;
}

int Listen(int sockfd, int backlog)
{
    int ret = listen(sockfd, backlog);
    if (ret < 0)
    {
        perr_exit("listen");
    }
    return ret;
}

int Accept(int sockfd, struct sockaddr *addr, socklen_t *addrlen)
{
    int ret;
again:
    ret = accept(sockfd, addr, addrlen);
    if (ret < 0)
    {
        if ((errno == ECONNABORTED) || (errno == EINTR))
            goto again;
        else
            perr_exit("accept");
    }
    return ret;
}

int Connect(int sockfd, const struct sockaddr *addr, socklen_t addrlen)
{
    int ret = connect(sockfd, addr, addrlen);
    if (ret < 0)
    {
        perr_exit("connect");
    }
    return ret;
}

int Close(int fd)
{
    int ret = close(fd);
    if (ret == -1)
    {
        perr_exit("close");
    }
    return ret;
}

ssize_t Read(int fd, void *buf, size_t count)
{
    ssize_t n;
again:
    if ((n = read(fd, buf, count)) == -1)
    {
        if (errno == EINTR)
            goto again;
        else
            return -1;
    }
    return n;
}

ssize_t Write(int fd, const void *buf, size_t count)
{
    ssize_t n;
again:
    if ((n = write(fd, buf, count)) == -1)
    {
        if (errno == EINTR)
            goto again;
        else
            return -1;
    }
    return n;
}

ssize_t Readn(int fd, void *buf, size_t count)
{
    ssize_t nleft = count;
    ssize_t nread = 0;
    char *ptr = buf;
    while (nleft > 0)
    {
        if ((nread = read(fd, ptr, nleft)) < 0)
        {
            if (errno == EINTR)
                nread = 0;
            else
                return -1;
        }
        else if (nread == 0)
        {
            break;
        }
        nleft -= nread;
        ptr += nread;
    }
    return count - nleft;
}

ssize_t Writen(int fd, const void *buf, size_t count)
{
    ssize_t nleft = count;
    ssize_t nwrite = 0;
    const char *ptr = buf;
    while (nleft > 0)
    {
        if ((nwrite = write(fd, ptr, nleft)) <= 0)
        {
            if ((errno == EINTR) && (nwrite < 0))
                nwrite = 0;
            else
                return -1;
        }
        nleft -= nwrite;
        ptr += nleft;
    }
    return count - nleft;
}

static ssize_t my_read(int fd, char *ptr)
{
    static int read_cnt = 0;
    static char *read_ptr = NULL;
    static char buf[100];
    if (read_cnt <= 0)
    {
    again:
        if ((read_cnt = read(fd, buf, sizeof(buf))) < 0)
        {
            if (errno == EINTR)
                goto again;
            else
                return -1;
        }
        else if (read_cnt == 0)
            return 0;
        read_ptr = buf;
    }
    read_cnt--;
    *ptr = *read_ptr++;
    return 1;
}

ssize_t ReadLine(int fd, void *buf, size_t MaxLength)
{
    ssize_t n;
    ssize_t rc;
    char c;
    char *ptr = buf;
    for (n = 1; n < MaxLength; n++)
    {
        if ((rc = my_read(fd, &c)) == 1)
        {
            *ptr++ = c;
            if (c == '\n')
                break;
        }
        else if (rc == 0)
        {
            *ptr = 0;
            return n - 1;
        }
        else
            return -1;
    }
    *ptr = 0;
    return n;
}