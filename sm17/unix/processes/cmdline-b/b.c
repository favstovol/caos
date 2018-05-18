#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <errno.h>
#include <error.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char *argv[]) {
    int pid, status, fd;
    pid = fork();
    if (!pid) {
        chdir("/usr/bin");
        fd = open("/tmp/log.txt", O_WRONLY|O_CREAT|O_TRUNC, 0600);
        dup2(fd, 1); close(fd);
        execlp("/bin/ls", "/bin/ls", "-l", NULL);
        fprintf(stderr, "Exec failed\n");
        _exit(1);
    }
    wait(&status);
    return 0;
}
