//***************************************************
/** 12 日付を表す構造体と人間を表す構造体 */
//***************************************************

#include <stdio.h>
#define NAME_LEN 128

struct Date
{
    int year;
    int month;
    int day;
};

typedef struct
{
    char name[NAME_LEN];
    struct Date birthday;
} Human;

void print_human(const Human *h)
{
    printf("%s (%04d年%02d月%02d日生まれ)\n", h->name, h->birthday.year, h->birthday.month, h->birthday.day);
}

int main(void)
{
    // int year, month, day;
    int i;
    struct Date today;

    Human member[] = {
        {"名無し１", {1902, 2, 11}},
        {"名無し２", {1999, 12, 31}},
        {"名無し３", {1804, 5, 21}}};

    printf("今日の日付を入力して下さい。\n");
    printf("年：");
    scanf("%d", &today.year);
    printf("月：");
    scanf("%d", &today.month);
    printf("日：");
    scanf("%d", &today.day);

    printf("今日は%c年%d月%d日です。\n", today.year, today.month, today.day);

    printf("--- 会員一覧表 ---\n");
    for (i = 0; i < sizeof(member) / sizeof(member[0]); i++)
    {
        print_human(&member[i]);
    }

    return 0;
}