
#include "Poll.h"

int Poll(struct pollfd *fds, nfds_t nfds, int timeout)
{
    int ret;
    if ((ret = poll(fds, nfds, timeout)) == -1)
        err_sys("poll error");

    return ret;
}