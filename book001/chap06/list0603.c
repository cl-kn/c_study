#include <stdio.h>

//***************************************************
/**
 * 関数の戻り値を引数とする、関数
 */
//***************************************************

/* 関数プロトタイプ宣言 */
int sqr(int);
int diff(int, int);

int main(void)
{
    int x, y;

    puts("二つの整数を入力して下さい\n");
    printf("整数 x >>");
    scanf("%d", &x);
    printf("整数 y >>");
    scanf("%d", &y);

    printf("x の2乗と、y の2乗の差は、「 %d 」", diff(sqr(x), sqr(y)));

    return 0;
}

int sqr(int x)
{
    return x * x;
}

int diff(int a, int b)
{
    return (a > b) ? a - b : b - a;
}