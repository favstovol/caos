#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

int readDouble(int fd, double *x) {
    int sz = sizeof(double);
    int cur_sz = 0;
    while (cur_sz != sz) {
        cur_sz += read(fd, (x + cur_sz), (sz - cur_sz));
        if (cur_sz == 0)
            return -1;
    }
    return 0;
}

void writeDouble(int fd, double *x) {
    int sz = sizeof(double);
    int cur_sz = 0;
    lseek(fd, -sz, SEEK_CUR);
    while (cur_sz != sz) {
        cur_sz += write(fd, (x + cur_sz), (sz - cur_sz));
    }
}

int main(int argc, char *argv[]) {
    int fd = open(argv[1], O_RDWR);
    if (fd < 0)
        return 0;
    double prev;
    if (readDouble(fd, &prev) < 0)
        return 0;
    double cur;
    int N;
    sscanf(argv[2], "%d", &N);
    for (int i = 2; i <= N; ++i) {
        if (readDouble(fd, &cur) < 0)
            return 0;
        double new_val = cur - prev;
        writeDouble(fd, &new_val);
        prev = new_val;
    }
}
