#include "Socket.h"

int Socket(int family, int type, int protocol)
{
    int n;
    if ((n = socket(family, type, protocol)) == -1)
        err_sys("socket error");
    return (n);
}

void Listen(int fd, int backlog)
{
    char *ptr;

    if ((ptr = getenv("listenq")) != NULL)
        backlog = atoi(ptr);

    if (listen(fd, backlog) < 0)
        err_sys("listen error");
}

int Bind(int fd, struct sockaddr *addr, socklen_t addrlen)
{
    int ret;
    if ((ret = bind(fd, addr, addrlen)) == -1)
        err_sys("bind error");

    return ret;
}

int Accept(int fd, struct sockaddr *addr, socklen_t *addrlen)
{
    int ret;
    if ((ret = accept(fd, addr, addrlen)) == -1)
        err_sys("accept error");

    return ret;
}