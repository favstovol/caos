#include <stdio.h>
#include <stdlib.h>

int main() {
    unsigned long long result = 0;
    unsigned long long a, b;
    size_t len = 10000;
    size_t nsize = 10000;
    char *line = NULL;
    line = malloc(len);
    while (getline(&line, &nsize, stdin) > 0) {
        sscanf(line, "%llx-%llx", &a, &b);
        result += (long long) b - (long long) a;
        nsize = len;
    }
    printf("%llu\n", result);
    free(line);
}
