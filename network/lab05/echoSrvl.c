#include <netinet/in.h>
#include "../common.h"
#include "../wrapper/Socket.h"
#include "../wrapper/Unistd.h"
#include "../lib/lib.h"

int main(int argc, char *argv[])
{
    int     listenfd, connfd;
    pid_t   childpid;
    socklen_t clilen;
    struct sockaddr_in cliaddr, servaddr;
    listenfd = Socket(AF_INET, SOCK_STREAM, 0);
    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    servaddr.sin_port = htons(SERV_PORT);
    Bind(listenfd, (SA *) &servaddr, sizeof(servaddr));
    Listen(listenfd, LISTENQ);
    signal(SIGCHLD, sig_chld);
    for ( ; ; )
    {
        clilen = sizeof(cliaddr);
        connfd = accept(listenfd, (SA *) &cliaddr, &clilen);
        if (connfd < 0)
            if (errno == EINTR)
                continue;
            else
                err_sys("accept error");
        if ((childpid = Fork()) == 0) //child process
        {
            Close(listenfd); //关闭监听套接字
            str_echo(connfd);
            exit(0);
        }
        Close(connfd); //父进程, 关闭已连接套接字
    }
}