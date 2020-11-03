//***************************************************
/** 時間情報の取得と扱い方
 * https://www.mm2d.net/main/prog/c/time-01.html
*/
//***************************************************

#include <stdio.h>
#include <time.h> //時刻情報を取得するtime()を含む

int main(void)
{
    //*********************************************
    // time_t t = time(NULL);
    // printf("%ld\n", t); //
    // printf("%zd\n", sizeof(time_t));

    //*********************************************
    // 曜日 月 日 時刻 年 の順で表示（英語）
    //非推奨？
    // printf("%s\n", ctime(&t));
    //*********************************************
    struct tm *tm;
    char *day_of_week[] = {"Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"};
    time_t t2 = time(NULL);
    tm = localtime(&t2);

    printf("%04d/%02d/%02d (%s) %02d:%02d:%02d\n,",

           tm->tm_year + 1900,
           tm->tm_mon + 1,
           tm->tm_mday,
           day_of_week[tm->tm_wday],
           tm->tm_hour,
           tm->tm_min,
           tm->tm_sec);

    return 0;
}

/*
    方法➀
    time_t t1;
    time(&t1); //引数に格納先へのポインタを渡す

    方法➁
    time_t t2 = time(NULL); // 戻り値を利用する

    time()の戻り値は、1970/1/1 0時0分0秒（UTC）からの経過秒数

    *******時刻表示を改善*******
    char *ctime(const time_t *timep);
    char *ctime_r(const time_t *timep, char *buf); スレッドセーフ

    *******年月日時分秒、各パラメータへの変換*******
    gmttime() GMT
    localtime() 地域情報に基づき時差を含めた時刻に変換

    struct tm *gmtime(const time_t *timep);
    struct tm *gmtime_r(const time_t *timep, struct tm *result);
    struct tm *localtime(const time_t *timep);
    struct tm *localtime_r(const time_t *timep, struct tm *result);

    **********struct tm構造体の構造**********
    struct tm {
        imt tm_sec;     秒(0 - 60)
        int tm_min;     分(0 - 59)
        int tm_hour;    時間(0 - 23)
        int tm_mday;    月内の日付(1 - 31)
        int tm_mon;     月(0 - 11)
        tin tm_year;    年 - 1900
        int tm_wday;    曜日(0-6, 日曜 = 0)
        int tm_yday;    年内通算日(0 - 365, 1月1日 = 0)
        int tm_isdst;   夏時間


    }


*/