#include <stdio.h>

int main() {
    int numb;
    int greatest = -1, almost = -1;
    while ((scanf("%d", &numb)) == 1) {
        if (numb >= greatest)
            almost = greatest, greatest = numb;
        else if (numb > almost)
            almost = numb;
    }
    printf("%d\n", greatest * almost);
}
