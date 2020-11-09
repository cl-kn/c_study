//***************************************************
/**「ポインタと配列【類似点と相違点から知る正しい扱い方】」
 * 課題１
 * サイト：https://monozukuri-c.com/langc-pointer-array/
 */
//***************************************************

#include <stdio.h>

int sumArray(long *pArray, int arrayNum, long *pSum);

int main(void)
{
    long num[] = {29, 9642, -3849, 628, 20};
    long sum = 0;
    int ret;

    //ケース1
    // ret = sumArray(num, sizeof(num) / sizeof(num[0]), &sum);

    //ケース2
    ret = sumArray(NULL, sizeof(num) / sizeof(num[0]), &sum);

    //ケース3
    // ret = sumArray(num, sizeof(num) / sizeof(num[0]), NULL);

    if (ret == 0)
    {
        printf("sum:%d", sum);
    }
    else
    {
        printf("ERROR");
    }

    return 0;
}

int sumArray(long *pArray, int arrayNum, long *pSum)
{
    int i, sum = 0;

    //NULLチェック
    if (pArray == NULL || pSum == NULL)
    {
        return -1;
    }

    // ポインタから配列にアクセス
    for (i = 0; i < arrayNum; i++)
    {
        sum += pArray[i];
    }

    *pSum = sum;

    return 0;
}