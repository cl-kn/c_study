//***************************************************
/** 要素数nのint型配列を受け取り、全要素に添え字と同じ値を代入する関数の作成 */
//***************************************************

#include <stdio.h>

void set_idx(int *v, int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        *(v + i) = i;
    }
}

int main(void)
{
    int i, array[5] = {2, 4, 6, 8, 10};
    printf("--------before--------\n");

    for (i = 0; i < 5; i++)
    {
        printf("array[%d] = %d\n", i, array[i]);
    }

    set_idx(array, 5);

    printf("--------after--------\n");
    for (i = 0; i < 5; i++)
    {
        printf("array[%d] = %d\n", i, array[i]);
    }

    return 0;
}