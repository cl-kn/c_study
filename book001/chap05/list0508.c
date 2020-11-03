#include <stdio.h>

//***************************************************
/**
 * 配列の全要素の並びを反転する
 */
//***************************************************

int main(void)
{
    int i;
    int array[7];

    // 要素に値を読み込む
    for (i = 0; i < 7; i++)
    {
        printf("array[%d] = ", i);
        scanf("%d", &array[i]);
    }

    for (i = 0; i < 3; i++)
    {
        // 一時保存用
        int temp = array[i];
        array[i] = array[6 - i];
        array[6 - i] = temp;
    }

    printf("--------------------reverse--------------------\n");

    for (i = 0; i < 7; i++)
    {
        printf("array[%d] = %d\n", i, array[i]);
    }
}

// int main(void)
// {
//     int array[5];
//     int i;
//     int value;

//     for (i = 0; i < 5; i++)
//     {
//         printf("array[%d] = ", i);
//         scanf("%d", &value);
//         array[i] = value;
//     }

//     printf("\n---------------------------------\n");

//     for (i = 0; i < 5; i++)
//     {
//         int j = 4;
//         int temp;

//         temp = array[j];
//         array[i] = temp;

//         j--;

//         printf("array[%d] = %d\n", i, array[i]);
//     }

//     return 0;
// }