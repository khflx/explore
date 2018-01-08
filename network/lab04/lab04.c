#include <netinet/in.h>

void
main()
{
    //listen第二个参数是规划状态为
    //established和syn_rcvd连接的个数
    struct sockaddr_in servaddr;
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    struct sockaddr_in6 serv;
    serv.sin6_addr = in6addr_any;
}
