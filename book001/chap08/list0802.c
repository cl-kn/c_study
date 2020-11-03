//***************************************************
/** 整数の2乗と浮動小数点数の2乗（関数形式マクロの利用） */
//***************************************************

#include <stdio.h>

#define sqr(x)((x) * (x))/* xの2乗値を求める関数形式マクロ */
// #define print_dog() (printf("dog\ndog\ndog\ndog\ndog\ndog\ndog"))
#define print_p() (printf("\n    |||||\n   ||-_-||\n   ||   ||\n     |||\n  ==m===w==////\n    |||||  ////\n   |||||||\n   |||||||\n  |||||||||\n ～～～～～～～\n ～～～～～～～"))


int main(void)
{
    int n;
    double x;

    int i = 10;
    double d = 20;

    printf("整数を入力してください\n>>");
    scanf("%d",&n);
    printf("入力値の2乗：%d\n",sqr(n));

    printf("実数を入力してください\n>>");
    scanf("%lf",&x);
    printf("入力値の2乗：%f\n",sqr(x));

    print_p();

    return 0;
}