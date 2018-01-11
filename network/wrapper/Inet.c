#include "Inet.h"
const char *Inet_ntop(int af, const void *src, char *dst, socklen_t size)
{
    const char *ptr;
    if ((ptr = inet_ntop(af, src, dst, size)) == NULL)
        err_sys("inet_ntop error");

    return ptr;
}

void Inet_pton(int af, const char *src, void *dst)
{
    if (inet_pton(af, src, dst) != 1)
        err_sys("inet_pton error");
}