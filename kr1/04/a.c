#include <stdint.h>

int64_t addmod(int64_t a, int64_t b, int64_t c) {
    a %= c;
    if (a < 0)
        a += c;
    b %= c;
    if (b < 0)
        b += c;
    uint64_t answer = ((uint64_t) a + (uint64_t) b) % (uint64_t) c;
    return answer;
}
