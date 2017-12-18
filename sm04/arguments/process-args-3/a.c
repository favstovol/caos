#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <stdint.h>

int main(int argc, char *argv[]) {
    for (int i = 1; i < argc; ++i) {
        char *eptr;
        errno = 0;
        long value = strtol(argv[i], &eptr, 10);
        if (!*(argv[i]) || *eptr || errno)
            printf("-1\n");
        else if (value == (int8_t) value)
            printf("1\n");
        else if (value == (int16_t) value)
            printf("2\n");
        else if (value == (int32_t) value)
            printf("4\n");
        else
            printf("-1\n");
    }
    return 0;
}
