#ifndef EXPLORE_NETWORK_COMMON_H
#define EXPLORE_NETWORK_COMMON_H

#define SERV_PORT   9877
#define LISTENQ     1024
#define MAXLINE     1024
/* poll阻塞选项, 通常为-1, 属于posix定义部分, 但glibc并不定义此常量, 详情请见man 2 poll 中的NOTES部分 */
#define INFTIM      -1

#define max(a,b)    ((a) > (b) ? (a) : (b))


typedef void    Sigfunc(int);
typedef struct  sockaddr SA;
#endif
