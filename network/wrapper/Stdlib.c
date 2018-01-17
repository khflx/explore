#include "Stdlib.h"

void *Malloc(size_t size)
{
    void *pVoid;
    if ((pVoid = malloc(size)) == NULL)
        err_sys("malloc error");
    return pVoid;
}