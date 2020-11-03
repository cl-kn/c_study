//***************************************************
/** 曜日を求める１：ツェラーの公式 */
//***************************************************

#include <stdio.h>

int dayofweek(int, int, int);

int main(void)
{
    int year = 2020, month = 10, day = 2, w;
    char *ws[] = {"日", "月", "火", "水", "木", "金", "土"};

    // printf("曜日を求めます\n");
    // printf("年：");
    // scanf("%d", &year);
    // printf("月：");
    // scanf("%d", &month);
    // printf("日：");
    // scanf("%d", &day);

    w = dayofweek(year, month, day);

    // printf("%d年 / %d月 / %d日 / %s曜日\n", year, month, day, ws[w]);

    // 以下のif文が無い場合、デバッグエラー
    if (w != -1)
    {
        printf("%d年 / %d月 / %d日 / %s曜日\n", year, month, day, ws[w]);
    }
    else
    {
        printf("取得に失敗しました。\n");
    }

    return 0;
}

int dayofweek(int year, int month, int day)
{
    if (month == 1 || month == 2)
    {
        year--;
        month += 12;
    }
    return (year + year / 4 - year / 100 + year / 400 + (13 * month + 8) / 5 + day) % 7;
}