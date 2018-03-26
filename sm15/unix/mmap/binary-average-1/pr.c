#include <sys/mman.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>

int main(int argc, char *argv[]) {
    int fd = open(argv[1], O_RDONLY);
    
    struct stat st;
    fstat(fd, &st);
    off_t file_length = st.st_size;

    double* mmaped_file = mmap(NULL, file_length, PROT_READ, MAP_SHARED, fd, 0);
    
    double accum = 0;
    long numb = file_length / sizeof(double);
    for (int i = 0; i < numb; ++i) {
        accum += mmaped_file[i];
    }

    printf("%a\n", accum / numb);

    munmap(mmaped_file, file_length);
    close(fd);
}
