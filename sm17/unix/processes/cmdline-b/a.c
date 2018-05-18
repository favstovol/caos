#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <errno.h>
#include <error.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char *argv[]) {
    int pid, status, fd_r, fd_w;
    pid = fork();
    if (!pid) {
        fd_w = open(argv[3], O_WRONLY|O_CREAT|O_TRUNC, 0666);
        fd_r = open(argv[2], O_RDONLY);
        dup2(fd_w, 1); close(fd_w);
        dup2(fd_r, 0); close(fd_r);
        execlp(argv[1], argv[1], NULL);
    }
    wait(&status);
    return 0;
}
