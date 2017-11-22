#include <stdio.h>
#include <ctype.h>

void translator(int *numb, int size, int dot_pos) {
    double answer = 0;
    if (dot_pos == -1)
        dot_pos = size;
    double power = 1;
    for (int i = 1; i < dot_pos; ++i)
        power = power * 7;
    for (int i = 0; i < dot_pos; ++i) {
        answer += power * (double) (numb[i] - '0');
        power /= 7;
    }
    for (int i = dot_pos + 1; i < size; ++i) {
        answer += power * (double) (numb[i] - '0');
        power /= 7;
    }
    printf("%.10g\n", answer);
}

int main() {
    int c;
    int numb[2000];
    int size = 0;
    int dot_pos = -1;
    while ((c = getchar()) != EOF) {
        if (isdigit(c) || c == '.') {
            if (c == '.')
                dot_pos = size;
            if (size > 2000)
                return 1;
            numb[size++] = c;
        } else {
            if (size > 0)
                translator(numb, size, dot_pos);
            size = 0;
            dot_pos = -1;
        }
    }
    if (size > 0)
        translator(numb, size, dot_pos);
    return 0;
}

