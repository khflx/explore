#ifndef EXPLORE_NETWORK_WRAPPER_POLL_H
#define EXPLORE_NETWORK_WRAPPER_POLL_H

#include <poll.h>
#include "../unit/error.h"

int Poll(struct pollfd *fds, nfds_t nfds, int timeout);
#endif
