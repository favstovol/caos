#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    int pfd[2];
    int pid;
    pipe(pfd);
    if (!(pid = fork())) {
        dup2(pfd[1], 1);
        close(pfd[1]);
        close(pfd[0]);
        int pid2;
        if (!(pid2 = fork())) {
            execlp("/bin/sh", "sh", "-c", argv[1], NULL);
            exit(0);
        }
        waitpid(pid2, NULL, 0);
        execlp("/bin/sh", "sh", "-c", argv[2], NULL);
        exit(0);
    }
    close(pfd[1]);
    int pid3;
    if (!(pid3 = fork())) {
        dup2(pfd[0], 0);
        close(pfd[0]);
        int fd_w = open(argv[4], O_WRONLY|O_CREAT|O_TRUNC, 0666);
        dup2(fd_w, 1); close(fd_w);
        execlp("/bin/sh", "sh", "-c", argv[3], NULL);
        exit(0);
    }
    close(pfd[0]);
    waitpid(pid, NULL, 0);
    waitpid(pid3, NULL, 0);
    return 0;
}
