//***************************************************
/** ctime()の利用 */
//***************************************************

#include <stdio.h>
#include <time.h>

char *asctime2(const struct tm *);
char *ctime2(const time_t *);

int main(void)
{
    time_t current = time(NULL);
    printf("time : [%s]", ctime2(&current)); // ctime2()により、改行削除

    return 0;
}

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

char *ctime2(const time_t *timer)
{
    return asctime2(localtime(timer));
}