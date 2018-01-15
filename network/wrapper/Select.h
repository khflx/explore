#ifndef EXPLORE_SELECT_H
#define EXPLORE_SELECT_H

#include <sys/select.h>
#include <errno.h>
#include "../unit/error.h"

int Select(int nfds, fd_set *readfds, fd_set *writefds, fd_set *exceptfds, struct timeval *timeout);
#endif