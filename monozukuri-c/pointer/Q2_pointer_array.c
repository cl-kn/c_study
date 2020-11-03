//***************************************************
/** 課題２
 * サイト：https://monozukuri-c.com/langc-pointer-array/ */
//***************************************************

#include <stdio.h>

int sortNumber(long *pNumber, int arrayNum);

int main(void)
{
    // 入力ケース１
    // long num[] = {10, -290, 3498, 28, -943};

    // 入力ケース２
    long num[] = {698, 1285, 0, -754, 9832, 1048, 18};
    int i;

    sortNumber(num, sizeof(num) / sizeof(num[0])); // 昇順並び替え

    for (i = 0; i < sizeof(num) / sizeof(num[0]); i++)
    {
        printf("%d\n", num[i]);
    }

    return 0;
}

int sortNumber(long *pNumber, int arrayNum)
{
    int i, j;
    long temp = 0;

    if (pNumber == NULL)
    {
        return -1;
    }

    for (i = 0; i < arrayNum; i++)
    {
        for (j = i + 1; j < arrayNum; j++)
        {
            if (pNumber[i] > pNumber[j])
            {
                temp = pNumber[i];
                pNumber[i] = pNumber[j];
                pNumber[j] = temp;
            }
        }
    }

    return 0;
}