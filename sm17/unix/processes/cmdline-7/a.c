#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <errno.h>
#include <error.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

int execCmd(const char *str) {
    int pid, status;
    pid = fork();
    if (pid < 0)
        return 1;
    if (!pid) {
        execlp("/bin/sh", "sh", "-c", str, NULL);
        exit(1);
    }
    waitpid(pid, &status, 0);
    if (WIFEXITED(status) && WEXITSTATUS(status) == 0)
        return 0;
    else
        return 1;
}

int main(int argc, char *argv[]) {
    if ((execCmd(argv[1]) == 0 || execCmd(argv[2]) == 0) && execCmd(argv[3]) == 0)
        return 0;
    else
        return 1;
}
