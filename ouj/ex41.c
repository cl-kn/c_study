#include <stdio.h>
int main(void)
{
    int i = 1;
    int input;

    printf("正の整数を入力してください ＞ ");
    scanf("%d", &input);

    while (i <= input)
    {
        if (input % 3 == 0) printf("%d ", input);
        input--;
    }

    return 0;
}

// 入力値～１において、３の倍数のみ表示するPG