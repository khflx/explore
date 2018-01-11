#ifndef EXPLORE_NETWORK_WRAPPER_WRITEN_H
#define EXPLORE_NETWORK_WRAPPER_WRITEN_H

#include "../libfree/libfree.h"
#include "../unit/error.h"

ssize_t Writen(int fd, const void *buff, size_t nbytes);

#endif
