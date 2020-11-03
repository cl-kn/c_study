#include <stdio.h>

//***************************************************
/**
 * 第13回 ポインタ
 * 例題6 文字列とポインタの関係
 */
//***************************************************

int main(void)
{
    int i;
    char *p, a[] = "pochi"; //char型のポインタ変数pと文字列を宣言
    p = a;                  //pにaの先頭アドレスを代入

    for (i = 0; i < sizeof(a); i++)
    {
        printf("%c", *(p + i));
    }

    int *p_int, num[5] = {1, 2, 3, 4, 5};
    p_int = num;

    for (i = 0; i < 5; i++)
    {
        // printf("%d", *p_int); // 11111
        printf("%d", *(p_int + i)); // 11111
        // *p_int は、配列num[]の先頭のアドレスを指す
        // よって、*(p_int + i)でとすると、ループが
        // num[0]
        // num[1]
        // num[2]
        // num[3]
        // num[4]
        // と回り、配列の要素がすべて出力される。
    }

    // size_t size_int = sizeof(int);
    // size_t size_double = sizeof(double);
    // printf("%d\n",&size_int);
    // printf("%d",&size_double);

    return 0;
}

/*
sizeof()：引数のメモリサイズを調べる
sizeof(型),sizeof(変数、定数、式)
*/