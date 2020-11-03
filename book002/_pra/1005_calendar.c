//***************************************************
/** カレンダー */
//***************************************************

#include <stdio.h>
// #include <stdlib.h>

int mday[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}; //1月～12月

int dayOfWeek(int, int, int); //year年month月day日の曜日を求める
int is_leap(int);             //うるう年判定（[0]...平年 [1]...うるう年）
int monthDays(int, int);      //year年month月の日数（28～31）
void put_calendar(int, int);  //カレンダー表示

int main(void)
{
    int year = 2020, month = 10;

    printf("[%d年%d月]\n", year, month);

    put_calendar(year, month);

    return 0;
}

//year年month月day日の曜日を求める
int dayOfWeek(int year, int month, int day)
{
    if (month == 1 || month == 2)
    {
        year--;
        month += 12;
    }
    return (year + year / 4 - year / 100 + year / 400 + (13 * month + 8) / 5 + day) % 7;
}
//うるう年判定(0 ... 平年 / 1 ... うるう年)
int is_leap(int year)
{
    return year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
}

//year年month月の日数(28～31)
int monthdays(int year, int month)
{
    //2月かどうか
    if (month-- != 2)
    {
        return mday[month];
    }
    return mday[month] + is_leap(year);
}

//カレンダー表示 ()
void put_calendar(int year, int month)
{
    puts("日 月 火 水 木 金 土");
    puts("--------------------");



}