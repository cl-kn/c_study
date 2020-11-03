//***************************************************
/**  課題１ 配列内の最大値探索
 * https://monozukuri-c.com/langc-array/
 * 10月29日
*/
//***************************************************

#include <stdio.h>

int main(void)
{
    //入力１
    // int num[] = {10, 3002, 529, 1920};

    // 入力２
    int num[] = {918, -792, 1002, 209, 652, 0x491};

    int i, max = 0;

    for (i = 0; i < sizeof(num) / sizeof(num[0]); i++)
    {
        if (max < num[i])
        {
            max = num[i];
        }
    }

    printf("max value = %d\n", max);

    return 0;
}