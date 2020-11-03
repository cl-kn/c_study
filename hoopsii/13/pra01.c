#include <stdio.h>

//***************************************************
/**
 * 第13回 ポインタ
 * 例題1 アドレスの表示
 */
//***************************************************

int main(void)
{
    int i, *p1; //int型の変数iとint型のポインタ変数p1の宣言
    i = 25;
    p1 = &i; //p1にiのアドレスを代入

    char *p2;     //char型のポインタ変数p2の宣言
    char f = 'A'; //char型の変数fを宣言
    p2 = &f;      //p2にfのアドレスを代入

    double s, *p3; //double型の変数sとdouble型のポインタ変数p3の宣言
    s = 2.5;
    p3 = &s; //p3にsのアドレスを代入

    //iの値とアドレスの16進数表記、10進数表記を出力
    printf("int = %d\n int_address(16) = %x\n int_address(10) = %d\n", i, p1, p1);
    printf("\n");

    printf("char = %c\n char_address(16) = %x\n char_address(10) = %d\n", f, p2, p2);
    printf("\n");

    printf("double = %lf\n double_address(16) = %x\n double_address(10) = %d\n", s, p3, p3);
    printf("\n");

    return 0;
}

/**「ポインタについて」
 * ポインタ＝変数のアドレスを記憶する変数で、通常の変数と同じく宣言が必要
 * int *p;  // pはポインタ変数
 * int i = 15;
 * p = &i;  //ポインタ変数に(変数の)アドレスを格納する時は、変数の前に & を付与
 * ※※型が不一致だとコンパイルエラー
 *
 * 変数の先頭に * が付く ⇒ ポインタ変数
 *      *point = 15;
 *      printf("%d\n", *ポインタ変数名);
 * ここで出力される値は、「ポインタ変数が指すアドレスにある値」
 *
 *
*/