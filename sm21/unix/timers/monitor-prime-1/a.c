#include <sys/time.h>
#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <inttypes.h>
#include <stdint.h>
#include <math.h>

uint32_t last_f = 0;
int counter = 0;

void sigvtalrm_h(int signo) {
    ++counter;
    printf("%" PRIu32 "\n", last_f);
    fflush(stdout);
    if (counter == 8)
        exit(0);
}

int main() {
    struct sigaction sa = {};
    sa.sa_flags = SA_RESTART;
    sa.sa_handler = sigvtalrm_h;
    sigaction(SIGVTALRM, &sa, NULL);

    struct itimerval to = {};
    to.it_value.tv_sec = 0;
    to.it_value.tv_usec = 100000;
    to.it_interval.tv_sec = 0;
    to.it_interval.tv_usec = 100000;
    setitimer(ITIMER_VIRTUAL, &to, NULL);

    uint32_t low, high;
    scanf("%" PRIu32, &low);
    scanf("%" PRIu32, &high);

    if (low < 2)
        low = 2;
    if (low != 2 && low % 2 == 0)
        ++low;
    while (low < high) {
        if (low == 2 || low == 3) {
            last_f = low;
            low += 1 + (low % 2);
            continue;
        }
        int flag = 1;
        uint32_t sq = (uint32_t) sqrt(low) + 2;
        if (sq >= low)
            sq = low - 1;
        for (uint32_t i = 3; i <= sq; i += 2)
            if (low % i == 0) {
                flag = 0;
                break;
            }
        if (flag)
            last_f = low;
        low += 2;
    }
    printf("%d\n", -1);
    fflush(stdout);
    exit(0);
}
