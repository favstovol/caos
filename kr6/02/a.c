#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <dlfcn.h>
#include <sys/mman.h>
#include <math.h>

int main(int argc, char *argv[]) {
    int fd = open(argv[1], O_WRONLY | O_CREAT | O_TRUNC);
    if (fd < 0) 
        return 1;
    int rows;
    sscanf(argv[2], "%d", &rows);
    int cols;
    sscanf(argv[3], "%d", &cols);
    ftruncate(fd, (size_t) sizeof(double) * (size_t) rows * (size_t) cols);

    
    double *matr = mmap(NULL,
        (size_t) sizeof(double) * (size_t) rows * (size_t) cols,
        PROT_WRITE, MAP_SHARED, fd, 0);
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            matr[i * rows + j] = 2.0 * sin((double) i) + 4.0 * cos((double) j / 2.0);
        }
    }
    munmap(matr, (size_t) sizeof(double) * (size_t) rows * (size_t) cols);
    close(fd);
}
