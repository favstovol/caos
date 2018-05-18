#include <stdio.h>
#include <ctype.h>

const double base = 7;
const int base_i = 7;

int main() {
    int c;
    int size = 0;
    int flag = 0;
    double answer = 0;
    double power = 1;
    do {
        c = getchar();
        if ((isdigit(c) && c < '0' + base_i) || c == '.') {
            if (c == '.') {
                flag = 1;
            } else {
                if (!flag) {
                    answer = answer * base + (double) (c - '0');
                } else {
                    power /= 7;
                    answer += (double) (c - '0') * power;
                }
            }
            ++size;
        } else {
            if (size > 0)
                printf("%.10g\n", answer);
            size = 0;
            flag = 0;
            answer = 0;
            power = 1;
        }
    } while (c != EOF);
    return 0;
}

