//***************************************************
/**  課題２ 2次元配列に九九表示
 * https://monozukuri-c.com/langc-array/
 * 10月29日
*/
//***************************************************

#include <stdio.h>

int main(void)
{
    int num[9][9] = {0};
    int i, k;

    for (i = 0; i < 9; i++)
    {
        for (k = 0; k < 9; k++)
        {
            // num[i][k] = num[i][k] * (k + 1);
            num[i][k] = (i + 1) * (k + 1);
            printf("%2d ", num[i][k]);
        }
        printf("\n");
    }

    // for (i = 0; i < 9; i++)
    // {
    //     for (k = i; k < 9; k++)
    //     {
    //         printf("%2d ", num[i][k]);
    //     }
    //     puts("\n");
    // }

    return 0;
}