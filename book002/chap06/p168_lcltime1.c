//***************************************************
/** 現在の日時・時刻を表示１ */
//***************************************************

#include <stdio.h>
#include <time.h>

void put_date(const struct tm *timer)
{
    char *wday_name[] = {
        "日",
        "月",
        "火",
        "水",
        "木",
        "金",
        "土",
    };
    printf("%4d年%02d月%02d日(%s)%02d時%02d分%02d秒",

           timer->tm_year + 1900,
           timer->tm_mon + 1,
           timer->tm_mday,
           wday_name[timer->tm_wday],
           timer->tm_hour,
           timer->tm_min,
           timer->tm_sec);
}

int main(void)
{
    time_t current;
    struct tm *timer;

    time(&current);              //time()でtime_t型の暦時刻として現在時刻を取得
    timer = localtime(&current); //要素別の時刻であるtm構造体に変換

    printf("現在の日時・時刻：");
    put_date(timer);

    return 0;
}