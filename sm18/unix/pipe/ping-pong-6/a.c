#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <stdio.h>

void son(long int n, int numb, int fdw) {
    while (1 == 1) {
        long int x;
        int ret_value = scanf("%ld", &x);
        if (ret_value <= 0 || x == n)
            return;
        printf("%d %ld\n", numb, x);
        fflush(stdout);
        dprintf(fdw, "%ld\n", x + 1);
    }
}

int main(int argc, char *argv[]) {
    long int n = strtol(argv[1], NULL, 10);
    int pfd1to2[2];
    pipe(pfd1to2);
    int pfd2to1[2];
    pipe(pfd2to1);
    int pid1;
    if (!(pid1 = fork())) {
        close(pfd1to2[0]);
        close(pfd2to1[1]);
        dup2(pfd2to1[0], 0);
        close(pfd2to1[0]);
        son(n, 1, pfd1to2[1]);
        close(pfd1to2[1]);
        exit(0);
    }
    int pid2;
    close(pfd2to1[0]);
    close(pfd1to2[1]);
    if (!(pid2 = fork())) {
        dup2(pfd1to2[0], 0);
        close(pfd1to2[0]);
        son(n, 2, pfd2to1[1]);
        close(pfd2to1[1]);
        exit(0);
    }
    close(pfd1to2[0]);
    dprintf(pfd2to1[1], "%ld\n", (long int) 1);
    close(pfd2to1[1]);
    waitpid(pid1, NULL, 0);
    waitpid(pid2, NULL, 0);
    printf("Done\n");
    return 0;
}
