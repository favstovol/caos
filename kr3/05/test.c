#include <stdio.h>

void process(unsigned *data, int count);

int main() {
    unsigned int v[5];
    v[0] = 1;
    v[1] = 2;
    v[2] = 3;
    v[3] = 4;
    v[4] = 5;
    process(v, 5);
    for (int i = 0; i < 5; ++i) {
        printf("%u\n", v[i]);
    }
}
