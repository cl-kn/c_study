//***************************************************
/** カレンダー表示 */
//***************************************************

#include <stdio.h>

int mday[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}; //各月の日数：1月～12月

int dayofweek(int, int, int); ///year年month月day日の曜日を求める
int is_leap(int);             //うるう年判定(0 ... 平年 / 1 ... うるう年)
int monthdays(int, int);      //year年month月の日数(28～31)
void put_calendar(int, int);  // カレンダー表示

int main(void)
{
    // int year, month;
    int year = 2020, month = 8;

    printf("**********calendar**********\n\n");
    printf("year ... %d\n", year);
    printf("month ... %d", month);
    // printf("year >> ");
    // scanf("%d", &year);
    // printf("month >> ");
    // scanf("%d", &month);
    puts("\n");

    put_calendar(year, month);

    return 0;
}

//year年month月１日の曜日を求める
int dayofweek(int year, int month, int day)
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
    //2月でない
    if (month-- != 2) // month-- で、mday[month]と一致する
    {
        return mday[month];
    }
    //2月のとき
    return mday[month] + is_leap(year);
}

//カレンダー表示
void put_calendar(int year, int month)
{
    int i;
    int wd = dayofweek(year, month, 1); // year年month月１日の曜日
    int mdays = monthdays(year, month); // year年month月の日数（28 or 30 or 31）

    printf(" 日 月 火 水 木 金 土 \n");
    printf("----------------------\n");

    printf("%*s", 3 * wd, ""); // 1日より左側分のスペースを表示

    for (i = 1; i <= mdays; i++)
    {
        printf("%3d", i);
        if (++wd % 7 == 0)
        { // 土曜日(7)を表示したら改行する
            putchar('\n');
        }
    }
    if (wd % 7 != 0)
    {
        putchar('\n');
    }
}

/*
30日の月（2,4,6,9,11）
31日の月（1,3,5,7,8,10,12）

1日の始まりの曜日、以前の曜日部分は"空白文字"
横7文字
*/
