#include <stdio.h>

int main() {
    unsigned long long m;
    scanf("%llu", &m);
    int c;
    unsigned long long cur = 0;
    unsigned long long answer = 0;
    do {
        c = getchar();
        if ('0' <= c && c <= '7') {
            cur = (cur * 8 + (unsigned long) (c - '0')) % m;
        } else {
            if (cur != 0 && cur % m > answer) {
                answer = cur % m;
            }
            cur = 0;
        }
    } while (c != EOF);
    printf("%llu\n", answer);
    return 0;
}
