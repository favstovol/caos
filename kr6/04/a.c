#include <stdio.h>
#include <stdlib.h>

int main() {
    unsigned long long result_w = 0;
    unsigned long long result_x = 0;
    unsigned long long a, b;
    size_t len = 10000;
    size_t nsize = 10000;
    char *line = NULL;
    line = malloc(len);
    char pr[10];
    while (getline(&line, &nsize, stdin) > 0) {
        sscanf(line, "%llx-%llx %s", &a, &b, pr);
        if (pr[1] == 'w')
            result_w += (long long) b - (long long) a;
        if (pr[2] == 'x')
            result_x += (long long) b - (long long) a;
        nsize = len;
    }
    printf("%llu\n%llu\n", result_w, result_x);
    free(line);
}
