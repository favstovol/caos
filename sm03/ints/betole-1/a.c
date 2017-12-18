#include <stdio.h>

enum { SQUARE_OF_BASE = 256 };
enum { MAX_LEN = 100 };

int main() {
    char s[MAX_LEN];
    int flag = 1;
    while (scanf("%s", s) == 1) {
        for (int i = 0; i < 4; ++i) {
            unsigned long a, b, c, d;
            if (scanf("%lx %lx %lx %lx", &a, &b, &c, &d) < 4) {
                if (flag)
                    printf("\n");
                return 0;
            }
            printf("%lu\n", d + SQUARE_OF_BASE
    * (c + SQUARE_OF_BASE * (b + SQUARE_OF_BASE * a)));
            flag = 0;
        }
    }
    if (flag)
        printf("\n");
}
