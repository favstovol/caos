#include <stdio.h>
#include <stdlib.h>

typedef struct Elem Elem;

struct Elem {
    int numb, count;
    Elem *prev;
    Elem *next;
};

Elem *find(Elem *head, int x) {
    Elem *cur = head;
    while (cur != NULL && cur->numb != x)
        cur = cur->next;
    return cur;
}

void delAll(Elem *head) {
    if (head == NULL)
        return;
    do {
        Elem *next = head->next;
        free(head);
        head = next;
    } while (head != NULL);
}

Elem *addToHead(Elem *head, int x) {
    Elem *cur = malloc(sizeof(Elem));
    if (cur == NULL) {
        delAll(head);
        exit(0);
    }
    cur->next = head;
    cur->prev = NULL;
    if (head != NULL)
        head->prev = cur;
    cur->numb = x;
    cur->count = 1;
    return cur;
}

Elem *moveToFront(Elem *cur, Elem *head) {
    if (head == cur)
        return head;
    Elem *left = cur->prev;
    Elem *right = cur->next;
    if (left != NULL)
        left->next = right;
    if (right != NULL)
        right->prev = left;
    cur->prev = NULL;
    cur->next = head;
    if (head != NULL)
        head->prev = cur;
    return cur;
}

void printAndDel(Elem *head) {
    if (head == NULL)
        return;
    Elem* tail = head;
    while ((*tail).next != NULL)
        tail = (*tail).next;
    while (tail != NULL) {
        printf("%d %d\n", (*tail).numb, (*tail).count);
        Elem *prev = tail;
        tail = (*tail).prev;
        free(prev);
    }
}

int main() {
    Elem *head = NULL;
    int x;
    while (scanf("%d", &x) == 1) {
        Elem *cur = find(head, x);
        if (cur == NULL) {
            head = addToHead(head, x);
        } else {
            head = moveToFront(cur, head);
            ++head->count;
        }
    }
    printAndDel(head);
}
