#include <stdint.h>
#include <time.h>
#include <stdio.h>

int main() {
    int days;
    while (scanf("%d", &days) == 1) {
        time_t a = days;
        time_t b = 24 * 60 * 60;
        time_t res;
        if (__builtin_mul_overflow(a, b, &res)) {
            printf("OVERFLOW\n");
            continue;
        }
        a = res;
        b = time(NULL);
        if (__builtin_add_overflow(a, b, &res)) {
            printf("OVERFLOW\n");
            continue;
        }
        struct tm *timeinfo = localtime(&res);
        char buf[20];
        strftime(buf, 20, "%Y-%m-%d", timeinfo);
        printf("%s\n", buf);
    }
}
