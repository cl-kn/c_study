//***************************************************
/** ifdef 機能 「条件コンパイル」
 * ・デバッグ用の処理を埋め込む
 *
 * 11/5
 * https://monozukuri-c.com/langc-ifdef/
 */
//***************************************************

#include <stdio.h>

#define D_DEBUG_ON //デバッグ時に有効化

int add(int num1, int num2)
{
#ifdef D_DEBUG_ON
    printf("num1:%d num:%d\n", num1, num2);
#endif
    return num1 + num2;
}

int main(void)
{
    int num;
    num = add(10, 20);

#ifdef D_DEBUG_ON
    printf("num:%d\n", num);
#endif

    return 0;
}