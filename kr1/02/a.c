#include <stdio.h>

int main() {
    long n;
    int w;
    scanf("%ld %d", &n, &w);
    long mx = 1;
    for (long i = 0; i + 1 < n; ++i) {
        mx *= 2;
    }
    for (long i = 0; i < mx; ++i) {
        printf("|%*lx|%*ld|%*ld|\n", w, i, w, i, w, i);
    }
    long zn = -mx + 1;
    for (long i = mx; i < mx * 2; ++i) {
        printf("|%*lx|%*ld|%*ld|\n", w, i, w, i, w, zn);
        ++zn;
    }
}
