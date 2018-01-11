#ifndef EXPLORE_NETWORK_LIB_H
#define EXPLORE_NETWORK_LIB_H

#include <sys/types.h>
#include <unistd.h>
#include "../common.h"
#include "../unit/error.h"
#include "../libfree/libfree.h"
#include "../wrapper/Stdio.h"
#include "../wrapper/Writen.h"
#include "../wrapper/Readline.h"

void str_echo(int sockfd);
void str_cli(FILE *fp, int sockfd);

void sig_chld(int signo);
void sig_pipe(int signo);

#endif
