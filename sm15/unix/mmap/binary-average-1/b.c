#include <sys/mman.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

int main() {
    int fd = open("output.bin", O_RDONLY);

    struct stat st;
    fstat(fd, &st);
    off_t file_length 
}
