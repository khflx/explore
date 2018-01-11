#ifndef EXPLORE_INET_H
#define EXPLORE_INET_H

#include <arpa/inet.h>
#include <stdlib.h>
#include "../unit/error.h"

const char *Inet_ntop(int af, const void *src, char *dst, socklen_t size);
void Inet_pton(int af, const char *src, void *dst);
#endif
