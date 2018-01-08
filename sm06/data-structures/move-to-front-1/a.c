#include <stdio.h>
#include <stdlib.h>

typedef struct Elem Elem;

struct Elem {
    int numb, count;
    Elem *prev;
    Elem *next;
};

int main() {
    Elem *head = NULL;
    int x;
    while (scanf("%d", &x) == 1) {
        Elem *cur = head;
        while (cur != NULL && (*cur).numb != x)
            cur = (*cur).next;
        if (cur == NULL) {
            cur = malloc(sizeof(Elem));
            (*cur).next = head;
            (*cur).prev = NULL;
            if (head != NULL)
                (*head).prev = cur;
            (*cur).numb = x;
            (*cur).count = 1;
        } else {
            if (cur == head) {
                ++(*cur).count;
                continue;
            }
            Elem *left = (*cur).prev;
            Elem *right = (*cur).next;
            if (left != NULL)
                (*left).next = right;
            if (right != NULL)
                (*right).prev = left;
            (*cur).prev = NULL;
            (*cur).next = head;
            if (head != NULL)
                (*head).prev = cur;
            ++(*cur).count;
        }
        head = cur;
    }
    if (head == NULL)
        return 0;
    Elem* tail = head;
    while ((*tail).next != NULL)
        tail = (*tail).next;
    while (tail != NULL) {
        printf("%d %d\n", (*tail).numb, (*tail).count);
        Elem *prev = tail;
        tail = (*tail).prev;
        free(prev);
    }
    return 0;
}
