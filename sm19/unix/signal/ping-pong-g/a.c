#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/signalfd.h>
#include <sys/wait.h>
#include <sys/types.h>

long int getX(int sfd, int fdr) {
    struct signalfd_siginfo fdsi;
    read(sfd, &fdsi, sizeof(struct signalfd_siginfo));
    long int x = -1;
    if (fdsi.ssi_signo == SIGUSR1) {
//        read(fdr, &x, sizeof(long int));
        ssize_t size = sizeof(long int);
        ssize_t cur = 0;
        while (cur != size) {
            ssize_t ret_value = read(fdr, &x, sizeof(long int));
            if (ret_value <= 0) {
                x = -1;
                break;
            }
            cur += ret_value;
        }
    }
    return x;
}

void sendX(long int x, int fdw) {
    write(fdw, &x, sizeof(long int));
}

void child(sigset_t mask, int *pfd, long int n, int numb, int pid_b) {
    int sfd;
    sfd = signalfd(-1, &mask, 0);
    int pid_bro;
    if (pid_b == 0)
        pid_bro = getX(sfd, pfd[0]);
    else
        pid_bro = pid_b;
    for (;;) {
        long int x;
        if (pid_b != 0) {
            x = getX(sfd, pfd[0]);
        } else {
            pid_b = -1;
            x = 1;
        }
        if (x == n + 1)
            exit(0);
        printf("%d %ld\n", numb, x);
        fflush(stdout);
        sendX(x + 1, pfd[1]);
        kill(pid_bro, SIGUSR1);
        if (x == n)
            exit(0);
    }
}

int main(int argc, char *argv[]) {
    long int n = strtol(argv[1], NULL, 10);
    int pfd[2];
    pipe(pfd);
    sigset_t mask;
    sigemptyset(&mask);
    sigaddset(&mask, SIGUSR1);
    sigprocmask(SIG_BLOCK, &mask, NULL);
    int pid1 = fork();
    if (pid1 == 0) {
        child(mask, pfd, n, 1, 0);
    }
    int pid2 = fork();
    if (pid2 == 0) {
        child(mask, pfd, n, 2, pid1);
    }
    sendX((long int) pid2, pfd[1]);
    kill(pid1, SIGUSR1);
//    sendX((long int) 1, pfd[1]);
//    kill(pid1, SIGUSR1);
    waitpid(pid1, NULL, 0);
    waitpid(pid2, NULL, 0);
    return 0;
}
