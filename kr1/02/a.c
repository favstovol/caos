#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>

#define i32 int32_t

int main() {
    i32 n;
    int w;
    scanf("%" PRId32 " %d", &n, &w);
    i32 mx = 1 << (n - 1);
    for (i32 i = 0; i < mx; ++i) {
        printf("|%*" PRIx32 "|%*" PRId32 "|%*" PRId32 "|\n", w, i, w, i, w, i);
    }
    i32 zn = -mx + 1;
    for (i32 i = mx; i < mx * 2; ++i) {
        printf("|%*" PRIx32 "|%*" PRId32 "|%*" PRId32 "|\n", w, i, w, i, w, zn);
        ++zn;
    }
}
