#include "lib.h"

void dg_echo(int sockfd, SA *pcliaddr, socklen_t clilen)
{
    ssize_t    n;
    socklen_t len;
    char    mesg[MAXLINE];
    while (1)
    {
        len = clilen;
        n   = Recvfrom(sockfd, mesg, MAXLINE, 0, pcliaddr, &len);
        Sendto(sockfd, mesg, n, 0, pcliaddr, len);
    }
}