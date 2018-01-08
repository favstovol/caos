#include <stdio.h>
#include <ctype.h>
#include <stdint.h>
#include <inttypes.h>

#define ull uint64_t

enum { DIGITS_NUMB = 10 };
enum { ALPHA_NUMB = 26 };

int main() {
    ull stack[1010];
    int head = 0;
    int c;
    ull cur_set = 0;
    do {
        c = getchar_unlocked();
        if (isalnum(c)) {
            int pos;
            if (isdigit(c)) {
                pos = c - '0';
            } else if (isupper(c)) {
                pos = c - 'A' + DIGITS_NUMB;
            } else {
                pos = c - 'a' + DIGITS_NUMB + ALPHA_NUMB;
            }
            cur_set |= (ull) 1 << pos;
        } else {
            if (cur_set != 0) {
                stack[head++] = cur_set;
                cur_set = 0;
            }
            if (c == '#') {
                stack[head++] = 0;
            } else if (c == '&') {
                stack[head - 2] &= stack[head - 1];
                --head;
            } else if (c == '|') {
                stack[head - 2] |= stack[head - 1];
                --head;
            } else if (c == '^') {
                stack[head - 2] ^= stack[head - 1];
                --head;
            } else if (c == '~') {
                stack[head - 1] = ~stack[head -1];
                stack[head - 1] &= ~((ull) 0) >> 2;
            }
        }
    } while (c != EOF);
    cur_set = stack[head - 1];
    if (cur_set == 0) {
        printf("#\n");
        return 0;
    }
    ull cur_pos = 1;
    char st[] = {'0', 'A', 'a'};
    int max_numb[] = {DIGITS_NUMB, ALPHA_NUMB, ALPHA_NUMB};
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < max_numb[i]; ++j) {
            if (cur_set & cur_pos) {
                putchar(st[i] + j);
            }
            cur_pos <<= 1;
        }
    }
    putchar('\n');
    return 0;
}
