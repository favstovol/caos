#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdint.h>
#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    int pid_s;
    int pfd[2];
    pipe(pfd);
    pid_s = fork();
    if (!pid_s) {
        close(pfd[1]);
        int pid_gs = fork();
        if (pid_gs) {
            int32_t x;
            int64_t sum = 0;
            for (;;) {
                int size = 4;
                int cur_size = 0;
                while (cur_size != size) {
                    cur_size += read(pfd[0], (&x) + cur_size, size - cur_size);
                    if (cur_size == 0)
                        break;
                }
                if (cur_size != 0)
                    sum += x;
                else
                    break;
            }
            close(pfd[0]);
            printf("%" PRId64 "\n", sum);
            fflush(stdout);
            exit(0);
        }
        close(pfd[0]);
        waitpid(pid_gs, NULL, 0);
        exit(0);
    }
    close(pfd[0]);
    int32_t x;
    while (scanf("%" PRId32, &x) == 1) {
        int size = 4;
        int cur_size = 0;
        while (cur_size != size)
            cur_size += write(pfd[1], (&x) + cur_size, size - cur_size);
    }
    close(pfd[1]);
    waitpid(pid_s, NULL, 0);
    return 0;
}
