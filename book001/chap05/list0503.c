#include <stdio.h>

//***************************************************
/**
 * 配列の各要素に先頭から順に 1,2,3,4,5 を代入して表示
 */
//***************************************************

int main(void)
{
    int array[5];
    int j = 5;

    for (int i = 0; i < 5; i++)
    {
        // array[i] = i + 1;
        // printf("array[%d] = %d\n", i, array[i]);
        array[i] = j;
        printf("array[%d] = %d\n", i, array[i]);
        j--;
    }

    return 0;
}