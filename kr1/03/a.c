#include <stdio.h>

#define ul unsigned long

int main() {
    long start; 
    if (scanf("%ld", &start) != 1) {
        printf("%d\n", 0);
        return 0;
    }
    long last = start;
    long cur;
    ul answer = 0;
    while (scanf("%ld", &cur) > 0) {
        if (cur < last) {
            ul delta;
            if ((start > 0 && last > 0) || (start < 0 && last < 0)) {
                delta = last - start;
            } else {
                delta = (ul) ((start ^ (~((ul) 0))) + 1) + (ul) last; 
            }
            if (delta > answer) {
                answer = delta;
            }
            start = cur;
            last = cur;
        } else {
            last = cur;
        }
    }
    ul delta;
    if ((start > 0 && last > 0) || (start < 0 && last < 0)) {
        delta = last - start;
    } else {
        delta = (ul) ((start ^ (~ ((ul) 0))) + 1) + (ul) last;
    }
    if (delta > answer) {
        answer = delta;
    }
    printf("%lu\n", answer);
}
