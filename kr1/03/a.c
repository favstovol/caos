#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>

#define ul uint32_t
#define l int32_t

uint32_t calc(int32_t start, int32_t last) {
    return (uint32_t) ((start ^ (~((uint32_t) 0))) + 1) + (uint32_t) last;
}

int main() {
    int32_t start; 
    if (scanf("%" PRId32, &start) != 1) {
        printf("%d\n", 0);
        return 0;
    }
    int32_t last = start;
    int32_t cur;
    uint32_t answer = 0;
    while (scanf("%" PRId32, &cur) > 0) {
        if (cur < last) {
            uint32_t delta;
            if ((start > 0 && last > 0) || (start < 0 && last < 0)) {
                delta = last - start;
            } else {
                delta = calc(start, last);
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
    uint32_t delta;
    if ((start > 0 && last > 0) || (start < 0 && last < 0)) {
        delta = last - start;
    } else {
        delta = calc(start, last);
    }
    if (delta > answer) {
        answer = delta;
    }
    printf("%" PRIu32 "\n", answer);
}
