#include <stdio.h>

//***************************************************
/**
 * 配列の全要素を別の配列にコピー
 */
//***************************************************

int main(void)
{
    int array1[5] = {11, 22, 33}; // 11,22,33,0,0 で初期化
    int array2[5];

    for (int i = 0; i < 5; i++)
    {
        array2[i] = array1[i];
    }

    printf("array1    array2\n");
    printf("----------------\n");

    for (int i = 0; i < 5; i++)
    {
        printf("%4d %8d\n", array1[i], array2[i]);
    }

    array1[2] = 55; // 影響を与えない

    printf("\n-------------------------------\n");

    for (int i = 0; i < 5; i++)
    {
        printf("%4d %8d\n", array1[i], array2[i]);
    }

    return 0;
}