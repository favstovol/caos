#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <errno.h>
#include <error.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

int mysys(const char *str) {
    int pid, status;
    pid = fork();
    if (pid < 0) {
        return -1;
    }
    if (!pid) {
        execl("/bin/sh", "sh", "-c", str, NULL); 
        exit(1);
    }
    waitpid(pid, &status, 0);
    if (WIFEXITED(status) && 0 <= WEXITSTATUS(status) && WEXITSTATUS(status) < 128)
        return WEXITSTATUS(status);
    else if (WIFSIGNALED(status))
        return 128 + WTERMSIG(status);
    return 0;
}

