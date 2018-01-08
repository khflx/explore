#include "libfree.h"

const char *inet_ntop_ipv4(int family, const void *addrptr, char *strptr, size_t len)
{
    const u_char *p = (const u_char *) addrptr;
    if (family == AF_INET)
    {
        //> INET_ADDRSTRLEN: 16
        //> 255.255.255.255\0 sizeof and strlen = 15
        char temp[INET_ADDRSTRLEN];
        snprintf(temp, sizeof(temp), "%d.%d.%d.%d", p[0], p[1], p[2], p[3]);
        if (strlen(temp) >= len)
        {
            errno = ENOSPC;
            return NULL;
        }
        strcpy(strptr, temp);
        return strptr;
    }
    errno = EAFNOSUPPORT;
    return NULL;
}