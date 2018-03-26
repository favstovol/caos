#include <unistd.h>
#include <stdio.h>
#include <errno.h>
#include <error.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    pid_t pid;
    for (int i = 1; i <= 3; ++i) {
        pid = fork();
        char s[10];
        long int x;
        if (pid == 0) {
            int c_size = 0;
            int r_size = 8;
            while (c_size != r_size)
                c_size += read(0, s + c_size, r_size - c_size);
            sscanf(s, "%ld", &x);
            printf("%d %ld\n", i, x * x);
            fflush(stdout);
            return 0;
        }
    }
    int status;
    for (int i = 0; i < 3; ++i) {
        while ((pid = wait(&status)) > 0)
            pid = wait(&status);
    }
    return 0;
}
