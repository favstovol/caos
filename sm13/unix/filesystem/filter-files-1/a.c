#include <sys/stat.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main(int argc, char *argv[]) {
    unsigned long long answer = 0;
    for (int i = 1; i < argc; ++i) {
        struct stat sinf;
        int res = lstat(argv[i], &sinf);
        if (res == -1)
            continue;
        if (!(S_ISREG(sinf.st_mode)))
            continue;
        if (sinf.st_nlink != 1)
            continue;
        answer += sinf.st_size;
    }
    printf("%llu\n", answer);
}
