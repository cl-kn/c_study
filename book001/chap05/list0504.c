#include <stdio.h>

//***************************************************
/**
 * 配列の全要素に 0.0 を代入して表示
 */
//***************************************************

int main(void)
{
    double array[5];

    for (int i = 0; i < 5; i++)
    {

        array[i] = 0.0;
        printf("array[%d] = %.1lf\n", i, array[i]);
    }

    return 0;
}