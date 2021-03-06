#include "Socket.h"

ssize_t Recvfrom(int sockfd, void *ptr, size_t nbytes, int flags, struct sockaddr *sa, socklen_t *salenptr)
{
    ssize_t     n;
    if ((n = recvfrom(sockfd, ptr, nbytes, flags, sa, salenptr)) < 0)
        err_sys("recvfrom error");

    return n;
}

int Socket(int family, int type, int protocol)
{
    int n;
    if ((n = socket(family, type, protocol)) == -1)
        err_sys("socket error");

    return n;
}

int Accept(int sockfd, struct sockaddr *addr, socklen_t *addrlen)
{
    int ret;
    if ((ret = accept(sockfd, addr, addrlen)) == -1)
            err_sys("accept error");

    return ret;
}

void Listen(int sockfd, int backlog)
{
    char *ptr;

    if ((ptr = getenv("listenq")) != NULL)
        backlog = atoi(ptr);

    if (listen(sockfd, backlog) < 0)
        err_sys("listen error");
}

void Connect(int sockfd, const struct sockaddr *addr, socklen_t addrlen)
{
    if (connect(sockfd, addr, addrlen) == -1)
        err_sys("connect error");
}

void Bind(int sockfd, struct sockaddr *addr, socklen_t addrlen)
{
    if (bind(sockfd, addr, addrlen) == -1)
        err_sys("bind error");
}

void Sendto(int sockfd, const void *ptr, size_t nbytes, int flags, const struct sockaddr *sa, socklen_t salen)
{
    if (sendto(sockfd, ptr, nbytes, flags, sa, salen) != (ssize_t) nbytes)
        err_sys("sendto error");
}

void Getsockname(int sockfd, struct sockaddr *localaddr, socklen_t *addrlen)
{
    if (getsockname(sockfd, localaddr, addrlen) == -1)
        err_sys("getsockname error");
}
void Getpeername(int sockfd, struct sockaddr *peeraddr, socklen_t *addrlen)
{
    if (getpeername(sockfd, peeraddr, addrlen) == -1)
        err_sys("getpeername error");
}

void Getsockopt(int sockfd, int level, int optname, void *optval, socklen_t *optlen)
{
    if (getsockopt(sockfd, level, optname, optval, optlen) == -1)
        err_sys("getsockopt error");
}
void Setsockopt(int sockfd, int level, int optname, const void * optval, socklen_t optlen)
{
    if (setsockopt(sockfd, level, optname, optval, optlen) == -1)
        err_sys("setsockopt error");
}

void Shutdown(int sockfd, int howto)
{
    if (shutdown(sockfd, howto) == -1)
        err_sys("shutdown error");
}