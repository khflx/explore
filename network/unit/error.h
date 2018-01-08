#ifndef EXPLORE_NETWORK_UNIT_ERROR_H
#define EXPLORE_NETWORK_UNIT_ERROR_H

#include <stdarg.h>
#include <syslog.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>

#define MAXLINE 1024

int daemon_proc;
void err_ret(const char *fmt, ...);
void err_sys(const char *fmt, ...);
void err_dump(const char *fmt, ...);
void err_msg(const char *fmt, ...);
void err_quit(const char *fmt, ...);
static void err_doit(int errnoflag, int level, const char *fmt, va_list ap);

#endif
