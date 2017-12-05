#include <stdio.h>
#include <ctype.h>

#define ull unsigned long long

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
                pos = c - 'A' + 10;
            } else {
                pos = c - 'a' + 36;
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
    int max_numb[] = {10, 26, 26};
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < max_numb[i]; ++j) {
            if (cur_set & cur_pos) {
                printf("%c", st[i] + j);
            }
            cur_pos <<= 1;
        }
    }
    printf("\n");
    return 0;
}
