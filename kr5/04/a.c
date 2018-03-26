#include <time.h>
#include <stdio.h>

int main() {
    long year, mon, wday;
    scanf("%ld %ld %ld", &year, &mon, &wday);
    --mon;
    long days_n[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    long days_v[12] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    long days = days_n[mon];
    if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0))
        days = days_v[mon];
    time_t rawtime;
    struct tm * new_time;
    time(&rawtime);
    new_time = gmtime(&rawtime);
    for (int i = 1; i <= days; ++i) {
        new_time->tm_year = year - 1900;
        new_time->tm_mon = mon;
        new_time->tm_mday = i;
        mktime(new_time);
        if (new_time->tm_wday == wday)
            printf("%d\n", i);
    }
}
