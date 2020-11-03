#include <stdio.h>

int main(void)
{
    // ポインター宣言 「型名 *変数名」
    int *p; //整数型ポインターp を宣言
    int i = 0x11223344;

    p = &i; // 変数のアドレスをポインターに格納

    // 「&」 アドレス演算子
    // 「%p」変換指定子
    printf("address i %p\n", &i);
    printf("address p %p\n", &p);

    // 「%0x」 16進数表示
    printf("value i %0x\n", i);

    // ポインターがアドレスのため、キャストして符号なし整数にしている
    printf("value p %0x\n", (unsigned int)p);

    // ポインターが示すアドレスに格納されているデータを表示
    printf("value *p %0x\n", *p);

    return 0;
}

/*
ポインター変数 p と整数変数 i を宣言する．
整数変数 i の先頭アドレスをポインター p に代入する．
各種演算子を使って，p や i アドレス等を調べる．
*/