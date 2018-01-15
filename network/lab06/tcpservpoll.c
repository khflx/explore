#include <netinet/in.h>
#include <poll.h>
#include <sys/types.h>
#include "../wrapper/Select.h"
#include "../wrapper/Socket.h"
#include "../wrapper/Unistd.h"
#include "../wrapper/Writen.h"
#include "../wrapper/Poll.h"

int main(int argc, char **argv)
{
    int     i, maxi, maxfd, listenfd, connfd, sockfd;
    int     nready;
    ssize_t n;
    char    buf[MAXLINE];
    socklen_t clilen;
    struct sockaddr_in cliaddr, servaddr;
    struct pollfd client[FOPEN_MAX];

    listenfd = Socket(AF_INET, SOCK_STREAM, 0);
    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family         = AF_INET;
    servaddr.sin_addr.s_addr    = htonl(INADDR_ANY);
    servaddr.sin_port           = htons(SERV_PORT);

    Bind(listenfd, (SA *) &servaddr, sizeof(servaddr));
    Listen(listenfd, LISTENQ);

    client[0].fd = listenfd;
    client[0].events = POLLRDNORM;
    for (i = 1; i < FOPEN_MAX; i++)
        client[i].fd = -1;
    maxi = 0;
    while (1)
    {
        nready  = Poll(client, maxi+1, INFTIM);

        if (client[0].revents & POLLRDNORM)
        {
            clilen = sizeof(cliaddr);
            connfd = Accept(listenfd, (SA *) &cliaddr, &clilen);
            for (i = 1; i < FOPEN_MAX; i++)
                if (client[i].fd < 0)
                {
                    client[i].fd = connfd;
                    break;
                }
            if (i == FOPEN_MAX)
                err_quit("too may clients");
            client[i].events = POLLRDNORM;
            if (i > maxi)
                maxi = i;
            if (--nready <= 0)
                continue;
        }
        for (i = 1; i <= maxi; i++)
        {
            if ((sockfd = client[i].fd) < 0)
                continue;
            if (client[i].revents & (POLLRDNORM | POLLERR))
            {
                if ((n = read(sockfd, buf, MAXLINE)) < 0)
                {
                    if (errno == ECONNRESET) //RST
                    {
                        Close(sockfd);
                        client[i].fd = -1;
                    }
                    else
                        err_sys("read error");
                }
                else if (n == 0) //读半部关闭
                {
                    Close(sockfd);
                    client[i].fd = -1;
                }
                else
                    Writen(sockfd, buf, (size_t) n);
                if (--nready <= 0)
                    break;
            }
        }
    }
}