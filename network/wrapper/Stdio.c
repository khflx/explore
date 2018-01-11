#include "Stdio.h"

char *Fgets(char *s, int size, FILE *stream)
{
    char *ptr;
    if ((ptr = fgets(s, size, stream)) == NULL)
        if (!feof(stream))
            err_sys("fgets error");

    return ptr;
}

int Fputs(const char *s, FILE *stream)
{
    int n;
    if ((n = fputs(s, stream)) == EOF)
        err_sys("fputs error");

    return n;
}