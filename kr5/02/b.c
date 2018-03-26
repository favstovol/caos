#include <fcntl.h>
#include <unistd.h>
#include <inttypes.h>
#include <stdint.h>
#include <stdio.h>

int main() {
    int fd = creat("text.out", 0000666);
    if (fd <= 0) {
        printf("There is a problem\n");
        return 0;
    }
    unsigned char buf[3] = {0, 0, 1};
    write(fd, buf, 1);
    write(fd, buf + 1, 1);
    write(fd, buf + 2, 1);
    close(fd);
}
