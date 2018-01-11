#include "../wrapper/Socket.h"
#include <time.h>
#include <unistd.h>
#include <arpa/inet.h>

#define MAXLINE 1024

int main(int argc, char *argv[])
{
    int listenfd, connfd;
    socklen_t len;
    struct sockaddr_in servaladdr, cliaddr;
    char buff[MAXLINE];
    time_t ticks;

    listenfd = Socket(AF_INET, SOCK_STREAM, 0);

    bzero(&servaladdr, sizeof(servaladdr));
    servaladdr.sin_family = AF_INET;
    servaladdr.sin_addr.s_addr = htonl(INADDR_ANY);
    servaladdr.sin_port = htons(13);

    Bind(listenfd, (SA *) &servaladdr, sizeof(servaladdr));
    Listen(listenfd, 5);
    for (; ; )
    {
        len = sizeof(cliaddr);
        connfd = Accept(listenfd, (SA *) &cliaddr, &len);
        printf(
            "connection from %s, prot %d\n",
            inet_ntop(
               AF_INET,
               &cliaddr.sin_addr,
               buff, sizeof(buff)
            ),
            (int) ntohs(cliaddr.sin_port)
        );
        ticks = time(NULL);
        snprintf(buff, sizeof(buff), "%.24s\r\n", ctime(&ticks));
        write(connfd, buff, strlen(buff));
        close(connfd);
    }
}