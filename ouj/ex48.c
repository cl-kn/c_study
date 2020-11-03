#include <math.h>
#include <stdio.h>

int main(void)
{
    double x;

    printf("正の数を入力 > ");
    scanf("%lf", &x);

    printf("%.3fの平方根は %.3f です。\n", x, sqrt(x));

    return 0;
}