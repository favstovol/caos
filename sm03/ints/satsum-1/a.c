#include <stdint.h>

uint32_t satsum(uint32_t v1, uint32_t v2) {
    uint32_t result;
    if (__builtin_add_overflow(v1, v2, &result))
        return ~0;
    else
        return result;
}
