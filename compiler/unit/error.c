#include "unit.h"

void
/**
 * 内存分配检验
 * @param len
 * @return
 */
*checked_malloc(int len)
{
    void *p = malloc(len);
    assert(p);

    return p;
}