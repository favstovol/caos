#include <fcntl.h>
#include <unistd.h>
#include <inttypes.h>
#include <stdint.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
    int fd = open(argv[1], O_RDONLY);
    unsigned char buf[3];
    int64_t sum = 0;
    while (1 == 1) {
        int flag = read(fd, buf, 1);
        if (flag < 1)
            break;
        read(fd, buf + 1, 1);
        read(fd, buf + 2, 1);
        // buf[0] - 2, buf[1] - 1, buf[2] - 0
        int32_t x = (uint32_t) buf[2] + (((uint32_t) buf[1]) << 8) + (((uint32_t) buf[0]) << 16);
        if (x & 0x800000)
            x ^= 0xff000000;
        sum += x;
    }
    printf("%" PRId64 "\n", sum);
    close(fd);
}
