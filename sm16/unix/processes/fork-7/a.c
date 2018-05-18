#include <unistd.h>
#include <stdio.h>
#include <errno.h>
#include <error.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

void f() {
    int x;
    if (scanf("%d", &x) <= 0) {
        exit(0);
    }
    pid_t pid = fork();
    if (pid < 0)
        exit(1);
    if (pid == 0)
        f();
    int status;
    waitpid(pid, &status, 0);
    if (!WIFEXITED(status) || WEXITSTATUS(status) != 0)
        exit(1);
    printf("%d\n", x);
    fflush(stdout);
    exit(0);
}

int main() {
    pid_t pid = fork();
    if (pid < 0) {
        printf("-1\n");
        return 0;
    }
    if (pid == 0) {
        f();
        exit(0);
    }
    int status;
    waitpid(pid, &status, 0);
    if (!WIFEXITED(status) || WEXITSTATUS(status) != 0)
        printf("-1\n");
    return 0;
}
