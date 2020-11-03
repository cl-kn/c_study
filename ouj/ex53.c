#include <stdio.h>

// 関数プロトタイプ宣言
double expo(double, int);

int main(void)
{
    double x = -2.7;
    int y = 3;

    printf("%.1lf の%d乗は %lf です。", x, y, expo(x, y));

    return 0;
}

double expo(double x, int y)
{

    double e;

    // １にｘをｙ回かける
    for (e = 1; y > 0; --y)
    {
        e *= x;
    }

    return e;
}