#include <netinet/in.h>
#include <strings.h>
#include <signal.h>

#include "../wrapper/Socket.h"
#include "../lib/lib.h"


void main()
{
    int tcpsockfd, udpsockfd, maxfdp1, connfd;
    char mesg[MAXLINE];
    size_t n;
    pid_t childpid;
    const int on = 1;
    socklen_t servlen, clilen;
    struct sockaddr_in servaddr, cliaddr;
    fd_set rset;
    servlen = sizeof(servaddr);

    /* TCP IPv4 Socket */
    bzero(&servaddr, servlen);
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    servaddr.sin_port        = htons(SERV_PORT);
    servaddr.sin_family      = AF_INET;
    tcpsockfd = Socket(AF_INET, SOCK_STREAM, 0);
    Setsockopt(tcpsockfd, SOL_SOCKET, SO_REUSEADDR, &on, sizeof(on));
    Bind(tcpsockfd, (SA *) &servaddr, servlen);
    Listen(tcpsockfd, LISTENQ);

    /* UDP IPv4 Socket */
    udpsockfd = Socket(AF_INET, SOCK_DGRAM, 0);
    bzero(&servaddr, servlen);
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    servaddr.sin_port = htons(SERV_PORT);
    Bind(udpsockfd, (SA *) &servaddr, servlen);

    /* TCP子进程处理 */
    signal(SIGCHLD, &sig_chld);

    FD_ZERO(&rset);
    maxfdp1 = max(tcpsockfd, udpsockfd)+1;
    while (1)
    {
        FD_SET(tcpsockfd, &rset);
        FD_SET(udpsockfd, &rset);
        if (select(maxfdp1, &rset, NULL, NULL, NULL) < 0)
            if (errno == EINTR)
                continue;
            else
                err_sys("select error");

        if (FD_ISSET(tcpsockfd, &rset))
        {
            clilen  = sizeof(cliaddr);
            connfd = Accept(tcpsockfd, (SA *) &cliaddr, &clilen);
            if ((childpid = Fork()) == 0)
            {
                Close(tcpsockfd);
                str_echo(connfd);
                exit(0);
            }
            Close(connfd);
        }
        if (FD_ISSET(udpsockfd, &rset))
        {
            clilen = sizeof(cliaddr);
            n = (size_t) Recvfrom(udpsockfd, mesg, MAXLINE, 0, (SA *) &cliaddr, &clilen);
            Sendto(udpsockfd, mesg, n, 0, (SA *) &cliaddr, clilen);
        }

    }

}