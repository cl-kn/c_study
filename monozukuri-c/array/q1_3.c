//***************************************************
/**  課題３ 配列の昇順並び替え
 * https://monozukuri-c.com/langc-array/
 * 10月29日
*/
//***************************************************

#include <stdio.h>

int main(void)
{
    // int num[] = {762, -98, 128, 8, 378};
    int num[] = {89, 1076, -102, -409, 2034, 489, 26};
    int i, j, temp;

    //バブルソート
    for (i = 0; i < sizeof(num) / sizeof(num[0]); i++)
    {
        for (j = i; j < sizeof(num) / sizeof(num[0]); j++)
        {
            if (num[i] > num[j])
            {
                temp = num[i];
                num[i] = num[j];
                num[j] = temp;
            }
        }
        printf("%d\n", num[i]);
    }

    return 0;
}