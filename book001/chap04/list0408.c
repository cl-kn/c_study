#include <stdio.h>

//***************************************************
/**
 * 入力値の整数分だけ * を表示
 */
//***************************************************

int main(void)
{
    printf("整数を入力してください\n");

    int num = 0;
    scanf("%d", &num);

    while (num-- > 0)
    {
        printf("* ");
    }

    return 0;
}