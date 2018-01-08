#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>

int main() {
    uint32_t answer = 0;
    uint32_t cur_set = 0;
    int numb;
    while ((scanf("%d", &numb)) == 1) {
        if (numb >= 0 && numb <= 31) {
            cur_set |= 1u << numb;
        } else {
            answer ^= cur_set;
            cur_set = 0;
        }
    }
    answer ^= cur_set;
    printf("%" PRIx32 "\n", answer);
    return 0;
}
