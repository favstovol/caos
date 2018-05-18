#include <stdint.h>
#include <time.h>
#include <stdio.h>

enum { HIND = 24, MINH = 60, SINH = 60, MAXLEN = 20 };

void printOverflow() {
    printf("OVERFLOW\n");
}

int main() {
    int days;
    while (scanf("%d", &days) == 1) {
        time_t a = days;
        time_t b = HIND * MINH * SINH;
        time_t res;
        if (__builtin_mul_overflow(a, b, &res)) {
            printOverflow();
            continue;
        }
        a = res;
        b = time(NULL);
        if (__builtin_add_overflow(a, b, &res)) {
            printOverflow();
            continue;
        }
        struct tm *timeinfo = localtime(&res);
        char buf[MAXLEN];
        strftime(buf, MAXLEN, "%Y-%m-%d", timeinfo);
        printf("%s\n", buf);
    }
}
