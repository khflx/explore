#ifndef EXPLORE_NETWORK_WRAPPER_STDIO_H
#define EXPLORE_NETWORK_WRAPPER_STDIO_H

#include <stdio.h>
#include "../unit/error.h"

/* 返回NULL表示到达EOF */
char    *Fgets(char *s, int size, FILE *stream);
int     Fputs(const char *s, FILE *stream);

#endif
