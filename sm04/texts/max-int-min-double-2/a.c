#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <stdint.h>

int main(int argc, char *argv[]) {
    FILE *file = 0;
    if (argc == 2) {
        file = fopen(argv[1], 'r');
        if (!file) {
            fprintf(stderr, "Error opening file for reading\n");
            return 1;
        }
    } else if (argc > 2) {
        fprintf(stderr, "Too many arguments\n");
        return 1;
    }
    char s[70];
    int was_long = 0;
    int32_t max_long = 0;
    int was_double = 0;
    double min_double = 0;
    while ((file != 0 && fscanf("%s", s) == 1) || (file == 0 && scanf("%s", s) == 1) {
        char *eptr;
        errno = 0;
        long value = strtol(s, &eptr, 10);
        if (!*s || *eptr || errno) {
        } else if (value == (int32_t) value) {
            if (was_long == 0 || value > max_long)
                max_long = value;
            was_long = 1;
        } else {
            continue;
        }
    }
}
