#include <ctype.h>

int mystrspccmp(const char *str1, const char *str2) {
    while (1 == 1) {
        while (isspace(*str1))
            ++str1;
        while (isspace(*str2))
            ++str2;
        if (*str1 != *str2 || *str1 == '\0')
            break;
        ++str1;
        ++str2;
    }
    if ((unsigned char) *str1 > (unsigned char) *str2)
        return 1;
    else if (*str1 == *str2)
        return 0;
    else
        return -1;
}
