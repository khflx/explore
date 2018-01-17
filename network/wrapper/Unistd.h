#ifndef EXPLORE_NETWORK_WRAPPER_UNISTD_H
#define EXPLORE_NETWORK_WRAPPER_UNISTD_H

#include <unistd.h>
#include "../unit/error.h"



ssize_t     Read(int fd, void *buf, size_t count);
void        Write(int fd, const void *buf, size_t count);
pid_t       Fork(void);
void        Close(int fd);

#endif
