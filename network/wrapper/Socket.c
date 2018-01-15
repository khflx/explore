#include "Socket.h"

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

void Shutdown(int sockfd, int howto)
{
    if (shutdown(sockfd, howto) == -1)
        err_sys("shutdown error");
}