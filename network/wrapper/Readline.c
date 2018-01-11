#include "Readline.h"

ssize_t Readline(int fd, void *buff, size_t maxlen)
{
    ssize_t n;
    if ((n = readline(fd, buff, maxlen)) == -1)
        err_sys("readline error");

    return n;
}