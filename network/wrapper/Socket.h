#ifndef EXPLORE_NETWORK_WRAPPER_SOCKET_H
#define EXPLORE_NETWORK_WRAPPER_SOCKET_H

#include <sys/socket.h>
#include "../unit/error.h"

typedef struct sockaddr SA;

int Socket(int family, int type, int protocol);
void Listen(int fd, int backlog);
int Bind(int fd, struct sockaddr *addr, socklen_t addrlen);
int Accept(int fd, struct sockaddr *addr, socklen_t *addrlen);

#endif
