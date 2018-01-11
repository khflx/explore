#include "libfree.h"

Sigfunc *signal_posix(int signo, Sigfunc *func)
{
    struct sigaction act, oact;

    act.sa_handler = func;
    sigemptyset(&act.sa_mask);
    act.sa_flags = 0;
    if (signo == SIGALRM)
    {
#ifdef SA_INTERRUPT
        act.sa_flags |= SA_INTERRUPT; //Sun Os 4.x
#endif
    }
    else
    {
#ifdef SA_RESTART
        act.sa_flags |= SA_RESTART; // SVR4, 4.4BSD
#endif
    }
    if (sigaction(signo, &act, &oact) < 0)
        return SIG_ERR;
    return oact.sa_handler;
}