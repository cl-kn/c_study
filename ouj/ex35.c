#include <stdio.h>
int main(void)
{
    int price = 0;
    int year = 0;

    printf("税抜き価格 ＞ ");
    scanf("%d", &price);

    printf("\n年度 ＞ ");
    scanf("%d", &year);

    if (year == 2020)
    {

        price *= 1.1;
    }
    else
    {

        price *= 1.05;
    }

    printf("税込み価格は%d円です。", price);

    return 0;
}