#include "Netdb.h"

struct hostent *Gethostbyname(const char *hostname)
{
    struct hostent *ret;
    if ((ret = gethostbyname(hostname)) == NULL)
    {
    }
}