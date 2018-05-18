#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

int state = 0;

void sigusr1_handler(int signo) {
    state = 0;
}

void sigusr2_handler(int signo) {
    state = 1;
}

int main() {
    struct sigaction sa1 = {};
    sa1.sa_flags = SA_RESTART;
    sa1.sa_handler = sigusr1_handler;
    sigaction(SIGUSR1, &sa1, NULL);
    struct sigaction sa2 = {};
    sa2.sa_flags = SA_RESTART;
    sa2.sa_handler = sigusr2_handler;
    sigaction(SIGUSR2, &sa2, NULL);
    printf("%d\n", getpid());
    fflush(stdout);
    int x;
    while (scanf("%d", &x) == 1) {
        if (state)
            printf("%d\n", x * x);
        else
            printf("%d\n", -x);
        fflush(stdout);
    }
    return 0;
}



