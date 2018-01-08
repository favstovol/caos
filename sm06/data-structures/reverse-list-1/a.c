#include <stdio.h>
#include <stdlib.h>

int main() {
    unsigned int n = 1;
    unsigned int k = 0;
    int *first = calloc(1, sizeof(int));
    int el;
    while (scanf("%d", &el) == 1) {
        ++k;
        if (k > n) {
            n *= 2;
            first = realloc(first, n * sizeof(int));
        }
        *(first + k - 1) = el;
    }
    for (int i = 1; i <= k; ++i) {
        printf("%d\n", *(first + k - i));
    }
    free(first);
    return 0;
}
