#include <stdint.h>

uint64_t is_nth(uint64_t x, int n) {
    return (((uint64_t) 1u) << n) & x;
}

uint32_t fixed_mul(uint32_t a, uint32_t b, int n) {
    uint64_t result = (uint64_t) a * (uint64_t) b;
    if (n != 0) {
        if (is_nth(result, n - 1) && (result & ((1u << (n-1)) - 1) || (is_nth(result, n)))) {
            result = (result >> n) + 1;
        } else {
            result >>= n;
        }
    }
    if (result >> 32 != 0) {
        return ~((uint32_t) 0);
    }
    return (uint32_t) result;
}
