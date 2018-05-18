#include <unistd.h>
#include <stdio.h>
#include <errno.h>
#include <error.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

void f(int n, int p) {
    if (n == 0) {
        printf("\n");
        fflush(stdout);
        return;
    }
    printf(" %d", p);
    fflush(stdout);
    pid_t pid = fork();
    if (pid == 0) {
        f(n - 1, p + 1);
        exit(0);
    }
    int status;
    waitpid(pid, &status, 0);
    exit(0);
}

int main() {
    int n;
    scanf("%d", &n);
    printf("1");
    fflush(stdout);
    f(n - 1, 2);
    return 0;
}
