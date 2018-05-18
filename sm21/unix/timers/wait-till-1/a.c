#include <sys/time.h>
#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <inttypes.h>
#include <stdint.h>

void sigalrm_handler(int signo) {
    exit(0);
}

int main() {
    struct sigaction sa = {};
    sa.sa_flags = SA_RESTART;
    sa.sa_handler = sigalrm_handler;
    sigaction(SIGALRM, &sa, NULL);

    int32_t s, ns;
    scanf("%" PRId32, &s);
    scanf("%" PRId32, &ns);
    int64_t ms = (int64_t) s * 1000 + (int64_t) ns / 1000000;
    
    struct timeval cur;
    gettimeofday(&cur, NULL);
    int64_t timeout = ms - (int64_t) cur.tv_sec * 1000 - (int64_t) cur.tv_usec / 1000;
    if (timeout <= 0)
        return 0;

    struct itimerval to = {};
    to.it_value.tv_sec = timeout / 1000;
    to.it_value.tv_usec = (timeout % 1000) * 1000;
    setitimer(ITIMER_REAL, &to, NULL);

    while (1 == 1)
        pause();
}
