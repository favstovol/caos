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

FPClass fpclassf(float value, int *psign) {
    union UType uvalue;
    uvalue.f = value;
    if (uvalue.p.order != 0 && uvalue.p.order != (1u << 8) - 1) {
        *psign = uvalue.p.sign;
        return FFP_NORMALIZED;
    }
    if (uvalue.p.order == 0) {
        *psign = uvalue.p.sign;
        if (uvalue.p.m == 0) {
            return FFP_ZERO;
        }
        return FFP_DENORMALIZED;
    } else {
        if (uvalue.p.m == 0) {
            *psign = uvalue.p.sign;
            return FFP_INF;
        }
        return FFP_NAN;
    }
}
