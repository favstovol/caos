#include <pthread.h>
#include <stdio.h>

pthread_t threads[10];

void *entry(void *wait_numb_ptr) {
    int *wait_numb = (int *) wait_numb_ptr;
    if (*wait_numb >= 0)
        pthread_join(threads[*wait_numb], NULL);
    printf("%d\n", (*wait_numb) + 1);
    return NULL;
}

int main() {
    int wait_for[10];
    for (int i = 0; i < 10; ++i) {
        wait_for[i] = i - 1;
        pthread_create(&threads[i], NULL, entry, &wait_for[i]);
    }
    pthread_join(threads[9], NULL);
    return 0;
}
