#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/signalfd.h>
#include <sys/wait.h>
#include <sys/types.h>

void child(sigset_t mask) {
    int sfd;
    struct signalfd_siginfo fdsi;
    ssize_t s;
    sfd = signalfd(-1, &mask, 0);
    if (sfd == -1)
        printf("sfd == -1\n");
    for (;;) {
        s = read(sfd, &fdsi, sizeof(struct signalfd_siginfo));
        if (s != sizeof(struct signalfd_siginfo))
            printf("ERROR\n");
        if (fdsi.ssi_signo == SIGUSR1) {
            printf("GOT IT\n");
        }
    }
    exit(0);
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
    if (pid1 > 0) {
        printf("Before child\n");
        child(mask);
    }
    kill(pid1, SIGUSR1);
    waitpid(pid1, NULL, 0);
    printf("Everything is done\n");
}
