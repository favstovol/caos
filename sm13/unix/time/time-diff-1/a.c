#include <time.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
    FILE *pFile = fopen(argv[1], "r");
    int year;
    int mon;
    int day;
    int hour;
    int min;
    int sec;
    time_t prev = 0;
    int flag = 0;
    while (fscanf(pFile, "%d/%d/%d %d:%d:%d", &year, &mon,
        &day, &hour, &min, &sec) > 0) {
        struct tm new_time;
        new_time.tm_sec = sec;
        new_time.tm_min = min;
        new_time.tm_hour = hour;
        new_time.tm_mday = day;
        new_time.tm_mon = mon - 1;
        new_time.tm_year = year - 1900;
        new_time.tm_isdst = -1;
        time_t new_sec = mktime(&new_time);
        long diff = (long) new_sec - (long) prev;
        if (flag)
            printf("%ld\n", diff);
        prev = new_sec;
        flag = 1;
    }
    fclose(pFile);
}
