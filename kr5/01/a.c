#include <sys/stat.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main(int argc, char *argv[]) {
    char buffer[1000];
    int low;
    int high;
    sscanf(argv[2], "%d", &low);
    sscanf(argv[3], "%d", &high);
    unsigned long long answer = 0;
    for (int i = low; i <= high; ++i) {
        sprintf(buffer, argv[1], i);
        struct stat sinf;
        int res = lstat(buffer, &sinf);
        if (res == -1)
            continue;
        if (!(S_ISREG(sinf.st_mode)))
            continue;
        if (sinf.st_gid != getgid())
            continue;
        answer += sinf.st_size;
    }
    printf("%llu", answer);
}
