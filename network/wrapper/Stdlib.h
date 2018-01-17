#ifndef EXPLORE_NETWORK_WRAPPER_STDLIB_H
#define EXPLORE_NETWORK_WRAPPER_STDLIB_H

#include <stdlib.h>
#include "../unit/error.h"

//当size为zero时, 会错误提示
void *Malloc(size_t size);

#endif
