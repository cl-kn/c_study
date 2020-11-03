//***************************************************
/** 静的記憶領域期間(static)をもつオブジェクトの暗黙の初期化の確認 */
//***************************************************

#include <stdio.h>

int fx;

int main(void)
{
    int i;
    static int si;    /* 0で初期化される */
    static double sd; /* 0.0で初期化される */
    static int sa[5]; /* 全要素が0で初期化される */

    printf("fx = %d\n", fx);
    printf("si = %d\n", si);
    printf("sd = %d\n", sd);

    for (i = 0; i < 5; i++)
    {
        printf("sa[%d] = %d\n",i, sa[i]);
    }

    return 0;
}