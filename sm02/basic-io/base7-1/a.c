#include <stdio.h>
#include <ctype.h>

const double base = 7;

double translator(int *numb, int size, int dot_pos) {
    double answer = 0;
    if (dot_pos == -1)
        dot_pos = size;
    double power = 1;
    for (int i = 1; i < dot_pos; ++i)
        power = power * base;
    for (int i = 0; i < dot_pos; ++i) {
        answer += power * (double) (numb[i] - '0');
        power /= base;
    }
    for (int i = dot_pos + 1; i < size; ++i) {
        answer += power * (double) (numb[i] - '0');
        power /= base;
    }
    return answer;
}

int main() {
    int c;
    int numb[2000];
    int size = 0;
    int dot_pos = -1;
    do {
        c = getchar();
        if ((isdigit(c) && c < '8') || c == '.') {
            if (c == '.')
                dot_pos = size;
            numb[size++] = c;
        } else {
            if (size > 0)
                printf("%.10g\n", translator(numb, size, dot_pos));
            size = 0;
            dot_pos = -1;
        }
    } while (c != EOF);
    return 0;
}

