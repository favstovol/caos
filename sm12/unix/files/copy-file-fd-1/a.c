#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

void copy_file(int in_fd, int out_fd) {
    ssize_t buf_size = 4096;
    ssize_t size = 0;
    unsigned char buf[buf_size];
    int is_end = 0;
    while (!is_end) {
        size = 0;
        ssize_t numb;
        while (size < buf_size) {
            numb = read(in_fd, (buf + size), buf_size - size);
            if (numb < 0)
                return;
            if (numb == 0) {
                is_end = 1;
                break;
            }
            size += numb;
        }
        ssize_t written_size = 0;
        while (written_size != size) {
            numb = write(out_fd, (buf + written_size), size - written_size);
            if (numb < 0)
                return;
            written_size += numb;
        }
    }
}
