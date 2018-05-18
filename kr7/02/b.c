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
    char *args[500];
    for (int i = 1; i < argc;) {
        int cnt = 1;
        args[0] = argv[i];
        while (i + cnt != argc && strcmp(argv[i + cnt - 1], "END") != 0) {
            args[cnt] = argv[i + cnt - 1];
            ++cnt;
        }
        if (i + cnt == argc)
            ++cnt;
        //for (int j = 0; j < cnt; ++j)
        //    printf("cnt[%d] = %s\n", j, args[j]);
        args[cnt - 1] = NULL;
        i += cnt;
        pid = fork();
        if (pid < 0)
            return 1;
        if (!pid) {
            execvp(args[0], args);
            exit(1);
        }
        waitpid(pid, &status, 0);
        if (WIFEXITED(status) && WEXITSTATUS(status) == 0)
            continue;
        else
            return 1;
    }
    return 0;
}
