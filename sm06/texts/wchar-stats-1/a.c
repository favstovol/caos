#include <stdio.h>
#include <wchar.h>
#include <wctype.h>
#include <locale.h>

int main() {
    long digit_count = 0;
    long upper_count = 0;
    long lower_count = 0;
    wint_t c;
    setlocale(LC_ALL, "");
    while ((c = getwchar()) != EOF) {
        if (iswdigit(c))
            ++digit_count;
        else if (iswlower(c))
            ++lower_count;
        else if (iswupper(c))
            ++upper_count;
    }
    printf("%ld\n%ld\n%ld\n", digit_count, upper_count, lower_count);
}
