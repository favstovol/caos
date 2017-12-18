#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <stdint.h>
#include <inttypes.h>
#include <string.h>
#include <ctype.h>

int main(int argc, char *argv[]) {
    int64_t summ = 0;
    double mean = 0;
    int32_t number = 0;
    int32_t sum_len = 0;
    for (int i = 1; i < argc; ++i) {
        if (*(argv[i]) == 'i') {
            int32_t numb;
            sscanf(argv[i] + 1, "%" PRId32, &numb);
            summ += numb;
        } else if (*(argv[i]) == 'd') {
            double numb;
            sscanf(argv[i] + 1, "%lf", &numb);
            mean += numb;
            number += 1;
        } else {
            sum_len += strlen(argv[i]);
        }
    }
    if (number == 0) {
        printf("0\n");
    } else {
        printf("%.10g\n", mean / number);
    }
    printf("%" PRId64 "\n%" PRId32 "\n", summ, sum_len);
}
