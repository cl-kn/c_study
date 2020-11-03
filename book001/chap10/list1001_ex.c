//***************************************************
/** 2つの整数の和と差を求める（動作しない）
 * ポインタを使っていないので、値の保存や戻り値を2つ以上返す（ような機能を使う）ことが出来ない
 * 「改変ver」
*/
//***************************************************

#include <stdio.h>

void calc(int, int, int *, int *);

int main(void)
{
    int a, b;
    int sum = 0, diff = 0;

    printf("2つの整数を入力\n");
    printf("a = ");
    scanf("%d", &a);
    printf("b = ");
    scanf("%d", &b);

    //calc関数の引数に、アド
    calc(a, b, &sum, &diff);

    printf("********************改変ver*****************\n");
    printf("a = %d\nb = %d\nsum = %d\ndiff = %d", a, b, sum, diff);

    return 0;
}

//2つの整数の和と差を求める関数
//引数にポインタを利用
void calc(int x, int y, int *sum, int *diff)
{
    *sum = x + y;
    // printf("%d", sum);
    *diff = (x > y) ? x - y : y - x;
    // printf("%d", diff);
}