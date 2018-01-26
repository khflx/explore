#ifndef EXPLORE_NETWORK_LIB_H
#define EXPLORE_NETWORK_LIB_H

#include <sys/types.h>
#include <syslog.h>
#include <unistd.h>
#include <fcntl.h>
#include "../common.h"
#include "../unit/error.h"
#include "../libfree/libfree.h"
#include "../wrapper/Stdio.h"
#include "../wrapper/Writen.h"
#include "../wrapper/Readline.h"
#include "../wrapper/Select.h"
#include "../wrapper/Unistd.h"
#include "../wrapper/Socket.h"

void dg_echo(int sockfd, SA *pcliaddr, socklen_t clilen);
void dg_cli(FILE *fp, int sockfd, const SA *pservaddr, socklen_t servlen);

void str_echo(int sockfd);
void str_cli(FILE *fp, int sockfd);

void sig_chld(int signo);
void sig_pipe(int signo);

int daemon_init(const char *pname, int facility);
void daemon_inetd(const char *pname, int facility);
#endif
