//***************************************************
/** カレンダー表示２
 *
 */
//***************************************************

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int mday[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}; //各月の日数：1月～12月

int day_of_week(int, int, int);        ///year年month月day日の曜日を求める
int is_leap(int);                      //うるう年判定(0 ... 平年 / 1 ... うるう年)
int month_days(int, int);              //year年month月の日数(28～31)
void put_calendar(int, int, int, int); // カレンダー表示

void make_calendar(int, int, char[][22]); //year年month月のカレンダーを2次元配列strに格納
void print(char[3][7][22], int);

int main(void)
{
    int y1, y2, m1, m2;
    y1 = 2020;
    y2 = 2020;
    m1 = 10;
    m2 = 12;

    // printf("開始年月を入力 「年」>> ");
    // scanf("%d", &y1);
    // printf("開始年月を入力 「月」>> ");
    // scanf("%d", &m1);
    // printf("終了年月を入力 「年」>> ");
    // scanf("%d", &y2);
    // printf("終了年月を入力 「月」>> ");
    // scanf("%d", &m2);

    putchar('\n');

    put_calendar(y1, m1, y2, m2);

    return 0;
}

//year年month月１日の曜日を求める
int day_of_week(int year, int month, int day)
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
int month_days(int year, int month)
{
    //2月でない
    if (month-- != 2) // month-- で、mday[month]と一致する
    {
        return mday[month];
    }
    //2月のとき
    return mday[month] + is_leap(year);
}

//year年month月のカレンダーを2次元配列strに格納
void make_calendar(int year, int month, char str[7][22])
{
    int i, k;
    int wd = day_of_week(year, month, 1);
    int mdays = month_days(year, month);
    char tmp[4];

    sprintf(str[0], "%10d / %02d     ", year, month); // タイトル（年 / 月）

    //タイトル以外のバッファクリア
    //str[1][0],str[2][0]...str[6][0]に null文字'\0'を代入し、str[1],str[2]...str[6]を空文字列にする
    for (k = 1; k < 7; k++)
    {
        str[k][0] = '\0';
    }

    k = 1;
    sprintf(str[k], "%*s", 3 * wd, ""); // 1日の左側を空白文字表示

    for (i = 1; i <= mdays; i++)
    {
        sprintf(tmp, "%3d", i); //i日の日付を追加
        strcat(str[k], tmp);    //土曜日を格納し
        if (++wd % 7 == 0)      //次の行に進む
        {
            k++;
        }
    }

    if (wd % 7 == 0)
    {
        k--;
    }
    else
    {
        // 最終日の右側に空白文字表示
        for (wd %= 7; wd < 7; wd++)
        {
            strcat(str[k], "   ");
        }
    }
    // 未使用行を空白文字表示
    while (++k < 7)
    {
        sprintf(str[k], "%21s", "");
    }
}

//3次元配列sbuf[][][]に格納されたカレンダーを横にn個並べて表示 (n >= 1 && n <= 3)
void print(char sbuf[3][7][22], int n)
{
    int i, j;
    for (i = 0; i < n; i++)
    {
        printf("%s    ", sbuf[i][0]);
    }
    putchar('\n');

    //以下誤り
    for (i = 0; i < n; i++)
    {
        printf(" 日 月 火 水 木 金 土    ");
    }
    putchar('\n');

    for (i = 0; i < n; i++)
    {
        printf("-----------------------   ");
    }
    putchar('\n');

    for (i = 1; i < 7; i++)
    {
        for (j = 0; j < n; j++) //カレンダー本体部を
        {
            printf("%s    ", sbuf[j][i]); //横にn個並べて表示
        }
        putchar('\n');
    }
    putchar('\n');
}

//y1年m1月～y2年m2月までのカレンダー表示
void put_calendar(int y1, int m1, int y2, int m2)
{
    int y = y1;
    int m = m1;
    int n = 0;
    char sbuf[3][7][22]; //バッファに備えている月数、カレンダー文字列のバッファ

    while (y <= y2)
    {
        // 2020年10月～2020年7月などの場合、break
        if (y == y2 && m > m2)
        {
            break;
        }

        make_calendar(y, m, sbuf[n++]);

        if (n == 3)
        {
            print(sbuf, n);
            n = 0;
        }

        m++;

        if (m == 13 && y < y2) //次の月へ
        {
            y++; //年を繰り越す
            m = 1;
        }
    }
    if (n)
    {
        print(sbuf, n); //未表示付きがあれば表示する
    }
}
