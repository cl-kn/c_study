//***************************************************
/** 削除用 */
//***************************************************

#include <stdio.h>
#include <time.h>

void put_data(const struct tm *time);

int main(void)
{
    struct tm *tm;
    time_t current = time(NULL);
    tm = localtime(&current);

    put_data(tm);

    return 0;
}

void put_data(const struct tm *time)
{
    char *days[] = {"日", "月", "火", "水", "木", "金", "土"};

    printf("%02d/%02d/%02d (%s) %02d:%02d:%02d",

           time->tm_year + 1900,
           time->tm_mon + 1,
           time->tm_mday,
           days[time->tm_wday],
           time->tm_hour,
           time->tm_min,
           time->tm_sec);
}