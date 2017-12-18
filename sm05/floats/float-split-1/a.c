#include <stdio.h>
#include <stdint.h>

struct FloatParts
{
    uint32_t m : 23;
    uint32_t order : 8;
    uint32_t sign : 1;
};

union UType
{
    float f;
    struct FloatParts p;
};

int main() {
    union UType number;
    while (scanf("%f", &number.f) == 1)
        printf("%d %d %x\n", number.p.sign, number.p.order, number.p.m);
}
