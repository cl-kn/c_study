#include <stdio.h>
int main(void)
{
    int i = 1;
    int input;

    printf("正の整数を入力してください ＞ ");
    scanf("%d", &input);

    while (i <= input)
    {
        printf("%d ", input--);
    }

    return 0;
}

// 入力値～１までを表示するPG