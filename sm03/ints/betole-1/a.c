#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>

enum { SQUARE_OF_BASE = 256 };
enum { MAX_LEN = 100 };

int main() {
    char s[MAX_LEN];
    int flag = 1;
    while (scanf("%s", s) == 1) {
        for (int i = 0; i < 4; ++i) {
            uint32_t a, b, c, d;
            if (scanf("%" PRIx32" %" PRIx32 "%" PRIx32 "%" PRIx32, &a, &b, &c, &d) < 4) {
                if (flag)
                    printf("\n");
                return 0;
            }
            printf("%" PRIu32 "\n", d + SQUARE_OF_BASE
    * (c + SQUARE_OF_BASE * (b + SQUARE_OF_BASE * a)));
            flag = 0;
        }
    }
    if (flag)
        printf("\n");
}
