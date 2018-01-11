#ifndef EXPLORE_NETWORK_LIBFREE_H
#define EXPLORE_NETWORK_LIBFREE_H

#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <signal.h>
#include "../common.h"
/****************************
 * 符合posix的信号函数
 ****************************
 */
Sigfunc *signal_posix(int signo, Sigfunc *func);

/***************************
 * I/O封装: 避免不足字节计数  #
 ***************************
 */
ssize_t readn(int fd, void *buff, size_t nbytes);
/* 确保write写入指定数量的数据  */
ssize_t writen(int fd, const void *buff, size_t nbytes);
ssize_t readline(int fd, void *buff, size_t maxlen);

/***************************
 * 协议相关函数             #
 ***************************
 */
int inet_pton_ipv4(int family, const char * strptr, void *addrptr);
const char *inet_ntop_ipv4(int family, const void *addrptr, char *strptr, size_t len);

/******************
 * 协议无关函数     #
 ******************
 */
char *sock_ntop(const struct sockaddr *sockaddr, socklen_t addren);
#endif
