#ifndef EXPLORE_UNIT_H
#define EXPLORE_UNIT_H

#include <assert.h>
#include <stdlib.h>

typedef char *string;
string String(char *);

typedef char Bool;
#define true    1
#define false   0

void *checked_malloc(int);

#endif