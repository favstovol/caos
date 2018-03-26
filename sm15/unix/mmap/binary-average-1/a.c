#include <sys/mman.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>

int main() {
    int fd = open("output.bin", O_CREAT | O_RDWR, 0644);
    int file_length = 100000 * sizeof(double);
    ftruncate(fd, file_length);
    double * mmaped_file = mmap(NULL, file_length, PROT_WRITE, MAP_SHARED, fd, 0);
    double accum = 0;
    for (int i = 0; i < 100000; ++i) {
        mmaped_file[i] = rand() % 1000;
        accum += mmaped_file[i];
    }
    printf("%a\n", accum / 100000);
    munmap(mmaped_file, file_length);
    close(fd);
}
