#include <fcntl.h>
#include <unistd.h>
#include <inttypes.h>
#include <stdint.h>
#include <stdio.h>

int32_t func(unsigned char *buf) {
    int32_t x = (uint32_t) buf[2] + (((uint32_t) buf[1]) << 8) + (((uint32_t) buf[0]) << 16);
    if (x & 0x800000)
        x ^= 0xff000000;
    return x;
}

int main(int argc, char *argv[]) {
    int fd = open(argv[1], O_RDONLY);
    unsigned char buf[3];
    int64_t sum = 0;
    while (1 == 1) {
        ssize_t cur_size = 0;
        while (cur_size != 3) {
            ssize_t ret_value = read(fd, buf + cur_size, 3 - cur_size);
            if (ret_value <= 0) {
                cur_size = -1;
                break;
            }
            cur_size += ret_value;
        }
        if (cur_size < 0)
            break;
        sum += func(buf);
    }
    printf("%" PRId64 "\n", sum);
    close(fd);
}
