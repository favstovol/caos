#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>

int main() {
    int64_t numb;
    char s[1000];
    int size = 0;
    int flag = 0;
    while ((scanf("%" PRId64, &numb)) == 1) {
        size = 0;
        flag = 0;
        if (numb == 0) {
            printf("0\n");
            continue;
        }
        if (numb < 0) {
            flag = 1;
            numb = -numb;
        }
        while (numb != 0) {
            if (numb % 3 < 2) {
                s[size] = '0' + numb % 3;
                numb /= 3;
            } else {
                s[size] = 'a';
                numb = numb / 3 + 1;
            }
            ++size;
        }
        if (flag)
            for (int i = 0; i < size; ++i) {
                if (s[i] == 'a')
                    s[i] = '1';
                else if (s[i] == '1')
                    s[i] = 'a';
            }
        for (int i = 1; i <= size; ++i)
            putchar(s[size - i]);
        putchar('\n');
    }
    return 0;
}
