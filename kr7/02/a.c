#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <errno.h>
#include <error.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>


int main(int argc, char *argv[]) {
    int pid, status;
    for (int i = 1; i < argc;) {
        int cnt = 1;
        while (i + cnt != argc && strcmp(argv[i + cnt - 1], "END") != 0)
            ++cnt;
        if (i + cnt != argc)
            argv[i + cnt - 1] = NULL;
        //for (int j = 0; j < cnt; ++j)
        //    printf("cnt[%d] = %s\n", j, args[j]);
        pid = fork();
        if (pid < 0)
            return 1;
        if (!pid) {
            execvp(argv[i], argv + i);
            exit(1);
        }
        waitpid(pid, &status, 0);
        i += cnt;
        if (WIFEXITED(status) && WEXITSTATUS(status) == 0)
            continue;
        else
            return 1;
    }
    return 0;
}
