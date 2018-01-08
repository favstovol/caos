#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>

#define ul uint32_t
#define l int32_t

int main() {
    l start; 
    if (scanf("%" PRId32, &start) != 1) {
        printf("%d\n", 0);
        return 0;
    }
    l last = start;
    l cur;
    ul answer = 0;
    while (scanf("%" PRId32, &cur) > 0) {
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
    printf("%" PRIu32 "\n", answer);
}
