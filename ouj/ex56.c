#include <stdio.h>

int myabs(int);

int main(void)
{
    int num = 0;

    printf("整数を入力してください ＞ ");
    scanf("%d", &num);

    printf("%d の絶対値は %d です。", num, myabs(num));

    return 0;
}

int myabs(int x)
{

    int abs = x;

    if (x >= 0)
    {
        return abs;
    }
    else
    {
        abs *= -1;
    }

    return abs;
}