#include "maxargs.h"

int maxargs(A_stm s)
{
    switch (s->kind)
    {
        case A_compoundStm:

            break;
        case A_assignStm:
            break;
        case A_printStm:
            break;
        default:
            assert(!"Wrong kind-value for A_stm");
    }
}