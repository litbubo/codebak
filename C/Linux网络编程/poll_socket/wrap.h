#ifndef __WRAP_H_
#define __WRAP_H_

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <sys/socket.h>
#include <sys/types.h>

void perr_exit(char *err);
int Socket(int domain, int type, int protocol);
int Bind(int sockfd, const struct sockaddr *addr, socklen_t addrlen);
int Listen(int sockfd, int backlog);
int Accept(int sockfd, struct sockaddr *addr, socklen_t *addrlen);
int Connect(int sockfd, const struct sockaddr *addr, socklen_t addrlen);
int Close(int fd);

ssize_t Read(int fd, void *buf, size_t count);
ssize_t Write(int fd, const void *buf, size_t count);
ssize_t Readn(int fd, void *buf, size_t count);
ssize_t Writen(int fd, const void *buf, size_t count);
//ssize_t my_read(int fd, char *ptr);
ssize_t ReadLine(int fd, void *buf, size_t MaxLength);

#endif // !__WRAP_H_
