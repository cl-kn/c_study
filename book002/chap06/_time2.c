//***************************************************
/** 時間情報の取得と扱い方
 * https://www.mm2d.net/main/prog/c/time-01.html
*/
//***************************************************

#include <stdio.h>
#include <time.h> //時刻情報を取得するtime()を含む

int main(void)
{
    struct tm *tm;
    char *day_of_week[] = {"Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"};
    time_t t2 = time(NULL);
    tm = localtime(&t2);

    printf("%04d/%02d/%02d (%s) %02d:%02d:%02d\n",

           tm->tm_year + 1900,
           tm->tm_mon + 1,
           tm->tm_mday,
           day_of_week[tm->tm_wday],
           tm->tm_hour,
           tm->tm_min,
           tm->tm_sec);

    return 0;
}
