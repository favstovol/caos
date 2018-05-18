#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char *argv[]) {
    int pfd[2];
    int pid;
    pipe(pfd);
    if (!(pid = fork())) {
        dup2(pfd[1], 1);
        close(pfd[1]);
        close(pfd[0]);
        execlp("/bin/sh", "sh", "-c", argv[1], NULL);
    }
    if (!(pid = fork())) {
        dup2(pfd[0], 0);
        close(pfd[0]);
        close(pfd[1]);
        execlp("/bin/sh", "sh", "-c", argv[2], NULL);
    }
    close(pfd[0]); close(pfd[1]);
    wait(0);
    wait(0);
    return 0;
}
