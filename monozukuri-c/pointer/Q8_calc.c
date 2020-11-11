//***************************************************
/** ポインタへの演算【番地に対する演算の特殊性を解説】
 * https://monozukuri-c.com/langc-pointer-calc/
 * 11/10
 */
//***************************************************

#include <stdio.h>

int main(void)
{
    char *pnum1;
    short *pnum2;
    long *pnum3;

    // ①：ポインタ変数のラベル
    printf("pnum1   :%d\n", sizeof(pnum1));
    printf("pnum2   :%d\n", sizeof(pnum2));
    printf("pnum3   :%d\n", sizeof(pnum3));

    printf("------------\n");

    // ②：ポインタ変数の型
    printf("char  * :%d\n", sizeof(char *));
    printf("short * :%d\n", sizeof(short *));
    printf("long  * :%d\n", sizeof(long *));

    printf("------------\n");

    // ③：ポインタ変数の参照先
    printf("*pnum1  :%d\n", sizeof(*pnum1));
    printf("*pnum2  :%d\n", sizeof(*pnum2));
    printf("*pnum3  :%d\n", sizeof(*pnum3));
 
    return 0;
}