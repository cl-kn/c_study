#include <stdio.h>

//***************************************************
/**
 * 第12回演習問題Ⅲ
 * １．うるう年判定プログラム
 */
//***************************************************

void checkYear(int);

int main(void)
{
    int year;

    printf("うるう年か判定します\n");
    printf("西暦を入力してください >> ");
    scanf("%d", &year);

    checkYear(year);

    return 0;
}

void checkYear(int year)
{
    if (year % 4 == 0 && !(year % 100 == 0) || year % 400 == 0)
    {
        printf("[%d年] はうるう年", year);
    }
    else
    {
        printf("[%d年] はうるう年ではない", year);
    }

    return;
}