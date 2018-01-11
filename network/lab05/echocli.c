#include <netinet/in.h>
#include "../unit/error.h"
#include "../wrapper/Socket.h"
#include "../wrapper/Inet.h"
#include "../lib/lib.h"

int main(int argc, char **argv)
{
    int     sockfd;
    struct sockaddr_in servaddr;

    if (argc != 2)
        err_quit("usage: echocli <IPaddress>");
    sockfd = Socket(AF_INET, SOCK_STREAM, 0);
    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port   = htons(SERV_PORT);
    Inet_pton(AF_INET, argv[1], &servaddr.sin_addr);
    Connect(sockfd, (SA *) &servaddr, sizeof(servaddr));
    socklen_t addrlen = sizeof(servaddr);
    char str[INET_ADDRSTRLEN];
    Getsockname(sockfd, (SA *) &servaddr, &addrlen);
    printf("%s\n", Inet_ntop(AF_INET, &servaddr.sin_addr, str, INET_ADDRSTRLEN));
    str_cli(stdin, sockfd);
    exit(0);

// 采用waitpid而不是wait的原因,
// wait阻塞到获得一个子进程终止, 此时处于信号处理函数阶段,
// 随操作系统实现可能会保留此时又一次的信号中断, 其他被忽略, 也就会产生zombie
// 而waitpid指定WNOHANG选项, 即当前无结束子进程不会阻塞
//    int i, sockfd[5];
//    struct sockaddr_in servaddr;
//    if (argc != 2)
//        err_quit("usage: echocli <IPaddress>");
//    for (i = 0; i < 5; i++) {
//        sockfd[i] = Socket(AF_INET, SOCK_STREAM, 0);
//        bzero(&servaddr, sizeof(servaddr));
//        servaddr.sin_family = AF_INET;
//        servaddr.sin_port   = htons(SERV_PORT);
//        Inet_pton(AF_INET, argv[1], &servaddr.sin_addr);
//        Connect(sockfd[i], (SA *) &servaddr, sizeof(servaddr));
//    }
//    str_cli(stdin, sockfd[0]);
//    exit(0);
}