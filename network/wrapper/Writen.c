#include "Writen.h"

ssize_t Writen(int fd, const void *buff, size_t nbytes)
{
    ssize_t n;
    if ((n = writen(fd, buff, nbytes)) == -1)
        err_sys("writen error");

    return n;
}