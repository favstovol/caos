#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>

int is_ok(uint32_t numb) {
    int least = -1;
    int most = -1;
    int cur = 1;
    while (numb != 0) {
        if (numb & 1) {
            if (least == -1)
                least = cur;
            most = cur;
        }
        ++cur;
        numb >>= 1;
    }
    if (most - least <= 23)
        return 1;
    else
        return 0;
}

int main() {
    uint32_t number;
    while ((scanf("%" PRIu32, &number)) == 1) {
        printf("%d\n", is_ok(number));
    }
}
