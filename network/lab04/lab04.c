#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>
#include <stdio.h>
void
main()
{
    int sockfd;
    struct sockaddr_in servaddr;
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = INADDR_ANY;
    servaddr.sin_port   = htons(3397);

    bind(sockfd, (struct sockaddr *) &servaddr, sizeof(servaddr));
    listen(sockfd, 5);

    struct sockaddr_in sock;
    socklen_t len = sizeof(sock);
    if (getsockname(sockfd, (struct sockaddr *) &sock, &len) == -1)
        printf("xxxx\n");

    char ip[16];
    inet_ntop(AF_INET, &sock.sin_addr, ip, sizeof(ip));
    printf("%s\n", ip);
}
