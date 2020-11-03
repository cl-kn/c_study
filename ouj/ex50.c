#include <stdio.h>
#include <math.h>

int main(void)
{
    double x = 0.7;
    double xx = -2.5;

    printf("%.1lf の %.1lf乗は、 %lf です。", x, xx, pow(x, -2.5));

    return 0;
}

// pow()関数・・・べき乗を求める