#include <stdio.h>

int main() {
    char s[100];
    int flag = 1;
    while (scanf("%s", s) == 1) {
        for (int i = 0; i < 4; ++i) {
            unsigned long a, b, c, d;
            if (scanf("%lx %lx %lx %lx", &a, &b, &c, &d) < 4) {
                if (flag)
                    printf("\n");
                return 0;
            }
            printf("%lu\n", d + 256 * (c + 256 * (b + 256 * a)));
            flag = 0;
        }
    }
    if (flag)
        printf("\n");
}

