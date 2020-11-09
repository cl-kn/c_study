//***************************************************
/** 【NULLポインタ】
 *  https://monozukuri-c.com/langc-nullpointer/
 * ・ポインタ変数にNULLを代入すると、参照無効を明示できる
 * 11/9
 */
//***************************************************

#include <stdio.h>

int subfunc(long *pnum)
{
    //NULLチェック
    if (pnum == NULL)
    {
        printf("ERR\n");
        return -1;
    }
}

int main(void)
{
    long num = 100;
    long *p_num = NULL;

    subfunc(p_num); // ERR が出力

    return 0;
}