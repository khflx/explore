#ifndef EXPLORE_NETWORK_WRAPPER_READLINE_H
#define EXPLORE_NETWORK_WRAPPER_READLINE_H

#include "../libfree/libfree.h"
#include "../unit/error.h"

ssize_t Readline(int fd, void *buff, size_t maxlen);

#endif
