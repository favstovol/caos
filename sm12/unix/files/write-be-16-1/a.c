#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
    int fd = creat(argv[1], S_IRUSR | S_IWUSR);
    unsigned short x;
    unsigned short reversed_x;
    while (scanf("%hu", &x) == 1) {
        reversed_x = (x << 8) | (x >> 8);
        write(fd, &reversed_x, 2);
    }
    close(fd);
}
