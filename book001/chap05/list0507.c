#include <stdio.h>

//***************************************************
/**
 * 配列の要素に値を読み込んで表示
 */
//***************************************************

int main(void)
{
    int array[5];
    int i;
    int value;

    for (i = 0; i < 5; i++)
    {
        printf("array[%d] = ", i);
        scanf("%d", &value);
        array[i] = value;
    }

    printf("\n---------------------------------\n");

    for (i = 0; i < 5; i++)
    {
        printf("array[%d] = %d\n", i, array[i]);
    }

    return 0;
}