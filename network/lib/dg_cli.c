#include "lib.h"
#include "../wrapper/Stdlib.h"

void dg_cli(FILE *fp, int sockfd, const SA *pservaddr, socklen_t servlen)
{
    int     n;
    char    sendline[MAXLINE], recvline[MAXLINE+1];
    socklen_t reply_len;
    struct sockaddr *preply_addr;
    preply_addr = (struct sockaddr *) Malloc(servlen);
    while (Fgets(sendline, MAXLINE, fp) != NULL)
    {
        Sendto(sockfd, sendline, strlen(sendline), 0, pservaddr, servlen);
        n = (int) Recvfrom(sockfd, recvline, MAXLINE, 0, preply_addr, &reply_len);
        //@注: 仅针对Berkeley实现
        //memcmp将会导致如果服务器是多宿的, sendto和recvfrom的ip地址不属于同一个子网时会出现问题
        //详情查看弱端系统(weak end system model)和强端系统(strong end system model)=> REC 1122
        //解决办法
        //1. DNS主机查询
        //2. 绑定IP地址到套接字
        if (reply_len != servlen || memcmp(pservaddr, preply_addr, reply_len) != 0)
        {
            printf("reply from %s (ignored)\n", sock_ntop(preply_addr, reply_len));
            continue;
        }
        recvline[n] = 0;
        Fputs(recvline, stdout);
        fflush(stdout);
    }
}