#include <stdio.h>
#include <wchar.h>
#include <wctype.h>
#include <locale.h>

int main() {
    long num = 0;
    long al_up = 0;
    long al_down = 0;
    wint_t c;
    setlocale(LC_ALL, "");
    while ((c = getwchar()) != EOF) {
        if (iswdigit(c))
            ++num;
        if (iswlower(c))
            ++al_down;
        if (iswupper(c))
            ++al_up;
    }
    printf("%ld\n%ld\n%ld\n", num, al_up, al_down);
}
