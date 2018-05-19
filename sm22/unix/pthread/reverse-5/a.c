#include <pthread.h>
#include <stdio.h>

void *entry(void *param) {
    int x;
    if (scanf("%d", &x) > 0) {
        pthread_t thread;
        pthread_create(&thread, NULL, entry, NULL);
        pthread_join(thread, NULL);
        printf("%d\n", x);
    }
    return NULL;
}

int main() {
    pthread_t first;
    pthread_create(&first, NULL, entry, NULL);
    pthread_join(first, NULL);
}
