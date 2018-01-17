#include <netinet/in.h>
#include "../wrapper/Socket.h"
#include "../wrapper/Inet.h"

int main()
{
    int sockfd;

    struct sockaddr_in servaddr;
    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port   = htons(SERV_PORT);
    Inet_pton(AF_INET, "127.0.0.1", &servaddr.sin_addr);

    sockfd = Socket(AF_INET, SOCK_DGRAM, 0);
    char str[] = "hello,world";
    Sendto(sockfd, str, strlen(str), 0, (SA *) &servaddr, sizeof(servaddr));
}