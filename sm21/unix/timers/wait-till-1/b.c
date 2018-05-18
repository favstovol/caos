#include <sys/time.h>
#include <stdio.h>

int main() {
    struct timeval cur;

    gettimeofday(&cur, NULL);
    printf("%ld %lld\n", (long) cur.tv_sec, (long long) cur.tv_usec);
}
