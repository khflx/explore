#include "Unistd.h"

ssize_t Read(int fd, void *buf, size_t count)
{
    ssize_t n;
    if ((n = read(fd, buf, count)) == -1)
        err_sys("read error");

    return n;
}

void Write(int fd, const void *buf, size_t count)
{
    if (write(fd, buf, count) != count)
        err_sys("write error");
}

pid_t Fork(void)
{
    pid_t pid;
    if ((pid = fork()) == -1)
        err_sys("fork error");

    return pid;
}

void Close(int fd)
{
    if (close(fd) == -1)
        err_sys("close error");
}