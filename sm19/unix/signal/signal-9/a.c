#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

int usr1_c = 0;
int usr2_c = 0;
int state = 0;

void sigusr1_handler(int signo) {
    ++usr1_c;
    state = 1;
}

void sigusr2_handler(int signo) {
    ++usr2_c;
    state = 2;
}

void sigterm_handler(int signo) {
    state = -1;
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
    struct sigaction sa3 = {};
    sa3.sa_flags = SA_RESTART;
    sa3.sa_handler = sigterm_handler;
    sigaction(SIGTERM, &sa3, NULL);

    sigset_t mask, oldmask;
    sigemptyset(&mask);
    sigaddset(&mask, SIGUSR1);
    sigaddset(&mask, SIGUSR2);
    sigaddset(&mask, SIGTERM);

    printf("%d\n", getpid());
    fflush(stdout);
    while (1) {
        sigprocmask(SIG_BLOCK, &mask, &oldmask);
        while (!state)
            sigsuspend(&oldmask);
        if (state == -1)
            exit(0);
        if (state == 1) {
            printf("%d\n%d\n", usr1_c - 1, usr2_c);
            fflush(stdout);
        }
        state = 0;
        sigprocmask(SIG_UNBLOCK, &mask, NULL);
    }
    return 0;
}



