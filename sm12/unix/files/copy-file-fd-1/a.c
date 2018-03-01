#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

void copy_file(int in_fd, int out_fd) {
    int buf_size = 4096;
    int size = 0;
    unsigned char buf[buf_size];
    int is_end = 0;
    while (!is_end) {
        size = 0;
        while (size < buf_size) {
            int numb = read(in_fd, (buf + size), buf_size - size);
            if (numb == 0) {
                is_end = 1;
                break;
            }
            size += numb;
        }
        int written_size = 0;
        while (written_size != size) {
            int numb = write(out_fd, (buf + written_size), size - written_size);
            written_size += numb;
        }
    }
}
