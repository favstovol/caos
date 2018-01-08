#include <stdio.h>
#include <stdlib.h>

typedef struct Elem Elem;

struct Elem {
    int numb;
    Elem *left;
    Elem *right;
};

Elem *insert(Elem *t, int x) {
    if (t == NULL) {
        t = malloc(sizeof(Elem));
        (*t).numb = x;
        (*t).left = NULL;
        (*t).right = NULL;
    } else if (x > (*t).numb) {
        (*t).right = insert((*t).right, x);
    } else if (x < (*t).numb) {
        (*t).left = insert((*t).left, x);
    }
    return t;
}

void RevOrder(Elem *t) {
    if (t) {
        RevOrder((*t).right);
        printf("%d ", (*t).numb);
        RevOrder((*t).left);
        free(t);
    }
}

int main() {
    Elem *head = NULL;
    int x;
    while (scanf("%d", &x) == 1) {
        while (x != 0) {
            head = insert(head, x);
            scanf("%d", &x);
        }
        if (head) {
            RevOrder(head);
        }
        printf("0 ");
    }
    printf("\n");
}
