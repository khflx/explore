#ifndef EXPLORE_NETWORK_WRAPPER_SOCKET_H
#define EXPLORE_NETWORK_WRAPPER_SOCKET_H

#include <sys/socket.h>
#include "../unit/error.h"

/*
 * 1. 需要注意信号中断slow system call
 * 2. connect被中断不可采用重启, 可用select TCPv2: 466
 */

ssize_t Recvfrom(int sockfd, void *ptr, size_t nbytes, int flags, struct sockaddr *sa, socklen_t *salenptr);
int Socket(int family, int type, int protocol);
int Accept(int sockfd, struct sockaddr *addr, socklen_t *addrlen);
void Listen(int sockfd, int backlog);
void Connect(int sockfd, const struct sockaddr *addr, socklen_t addrlen);
void Bind(int sockfd, struct sockaddr *addr, socklen_t addrlen);
void Sendto(int sockfd, const void *ptr, size_t nbytes, int flags, const struct sockaddr *sa, socklen_t salen);
void Getsockname(int sockfd, struct sockaddr *localaddr, socklen_t *addrlen);
void Getpeername(int sockfd, struct sockaddr *peeraddr, socklen_t *addrlen);
void Shutdown(int sockfd, int howto);
#endif
