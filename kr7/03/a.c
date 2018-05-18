#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <errno.h>
#include <error.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>


int main(int argc, char *argv[]) {
    int pid;
    int pfd[2];
    pipe(pfd);
    if (!fork()) {
        close(pfd[0]);
        dup2(pfd[1], 1);
        close(pfd[1]);
        execlp(argv[1], argv[1], NULL);
        exit(0);
    }
    close(pfd[1]);
    wait(0);
    int fd = creat(argv[0], 0660);
    pid = fork();
    if (!pid) {
        dup2(pfd[0], 0);
        dup2(fd, 1);
        dup2(fd, 1
    }
}
