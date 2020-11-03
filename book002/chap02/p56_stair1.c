//***************************************************
/** 表示文字を1文字ずつずらして表示：１ */
//***************************************************

#include <stdio.h>

int main(void)
{
    int i, j, inputNum;

    printf("何段表示しますか？\n>>");
    scanf("%d", &inputNum);

    for (i = 1; i <= inputNum; i++)
    {
        // printf("%d\n", i);
        for (j = 1; j < i; j++) // 「j-1」個の空白を表示
        {
            putchar(' '); //空白文字
        }
        printf("%d\n", i % 10);
    }

    return 0;
}