#include <stdio.h>

//***************************************************
/**
 * 3-1 10個の入力値を最後から表示する
 */
//***************************************************

void printNum(int array[]);

int main(void)
{
    int array[10];
    printf("10個の整数を入力してください\n");

    for (int i = 0; i < 10; i++)
    {
        printf("%d個目 ＞＞ ", i + 1);
        scanf("%d", &array[i]);
    }

    printNum(array);

    return 0;
}

void printNum(int array[])

{
    // int count = sizeof(array) / sizeof(array[0]);

    printf("\n最後に入力した順から値を表示します。\n");
    for (int i = 9; i >= 0; i--)
    {
        printf("%d, ", array[i]);
    }
}