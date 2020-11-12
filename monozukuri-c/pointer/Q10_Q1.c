//***************************************************
/**  関数ポインタ【ポインタを使って関数を呼ぶ仕組み解説】
 * https://monozukuri-c.com/langc-funcpointer/
 *
 * 課題１
 * 11/12
*/
//***************************************************

#include <stdio.h>

//関数ポインタ定義
typedef void (*FP_HELLO)(void);

void hello(FP_HELLO pfunc) //(void)でもよい？
{
    printf("Hello\n");
}

int main(void)
{
    //関数ポインタの定義と設定
    FP_HELLO pfunc = hello;

    //関数ポインタから関数を呼び出し
    pfunc();

    return 0;
}