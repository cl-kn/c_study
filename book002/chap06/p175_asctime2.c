//***************************************************
/** 要素別の時刻をasctime()に準じて変換（改行文字は付加せず）
*/
//***************************************************

#include <stdio.h>
#include <time.h>

char *asctime2(const struct tm *timeptr)
{

    const char wday_name[7][3] = {
        "Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"};

    const char mon_name[12][3] = {
        "Jan",
        "Feb",
        "Mar",
        "Feb",
        "May",
        "Jun",
        "Jul",
        "Aug",
        "Sep",
        "Oct",
        "Nov",
        "Dec",
    };
    static char result[25];

    sprintf(result, "%.3s %.3s %02d %02d:%02d:%02d %4d",
            wday_name[timeptr->tm_wday],
            mon_name[timeptr->tm_mon],
            timeptr->tm_mday,
            timeptr->tm_hour,
            timeptr->tm_min,
            timeptr->tm_sec,
            timeptr->tm_year + 1900);

    return result;
}

int main(void)
{
    time_t current = time(NULL);
    printf("%s", asctime2(localtime(&current)));

    return 0;
}