#include "Select.h"

int Select(int nfds, fd_set *readfds, fd_set *writefds, fd_set *exceptfds, struct timeval *timeout)
{
    int ret;
    if ((ret = select(nfds, readfds, writefds, exceptfds, timeout)) == -1)
        if (errno != EINTR)
            err_sys("select error");
    return ret;
}
