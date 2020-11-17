//***************************************************
/** 動的メモリ【ヒープメモリの使い方と獲得する方法】

 * https://monozukuri-c.com/langc-dynamic-memory/
 * 課題
 * 11/17
 */
//***************************************************

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int i;

    //  long型の1000個分の動的メモリを確保する
    long *long_data = (long *)malloc(sizeof(long) * 1000);

    //  [0]～[999]の動的メモリに0～999の値を順に設定する
    for (i = 0; i <= 999; i++)
    {
        long_data[i] = i;
    }

    //  [990]～[999]のメモリ内容を画面に表示する
    for (i = 990; i <= 999; i++)
    {
        printf("[%d] = %d\n", i, long_data[i]);
    }

    //  動的メモリを解放する
    free(long_data);
    return 0;
}