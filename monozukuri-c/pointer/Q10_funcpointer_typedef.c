//***************************************************
/** 関数ポインタ
 * https://monozukuri-c.com/langc-funcpointer/
 * typedefで定義した場合
 * 11/12
 */
//***************************************************

#include <stdio.h>

typedef void (*FP_FUNC)(int);

void sub(FP_FUNC pfunc, int num)
{
    return;
}

int main(void)
{
    FP_FUNC pfunc = NULL;
    sub(pfunc, 100);

    return 0;
}