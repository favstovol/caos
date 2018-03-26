#include <unistd.h>
#include <stdio.h>
#include <errno.h>
#include <error.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    fflush(stdout);
    pid_t pid_son = fork();
    if (pid_son == 0) {
        pid_t pid_gson = fork();
        if (pid_gson == 0) {
            printf("3 ");
            fflush(stdout);
            return 0;
        }
        int gstatus;
        waitpid(pid_gson, &gstatus, 0);
        printf("2 ");
        fflush(stdout);
        return 0;
    }
    int status;
    waitpid(pid_son, &status, 0);
    printf("1\n");
    fflush(stdout);
    return 0;
}
