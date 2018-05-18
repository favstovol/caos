#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

int counter = 0;

void sigint_handler(int signo) {
    if (counter < 4) {
        printf("%d\n", counter);
        fflush(stdout);
        ++counter;
    } else {
        exit(0);
    }
}

int main() {
    struct sigaction sa = {};
    sa.sa_flags = SA_RESTART;
    sa.sa_handler = sigint_handler;
    sigaction(SIGINT, &sa, NULL);
    printf("%d\n", getpid());
    fflush(stdout);
    while (1) {
        pause();
    }
    return 0;
}
