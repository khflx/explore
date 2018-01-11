#ifndef EXPLORE_NETWORK_WRAPPER_UNISTD_H
#define EXPLORE_NETWORK_WRAPPER_UNISTD_H

#include <unistd.h>
#include "../unit/error.h"

pid_t Fork(void);
void Close(int fd);

#endif
