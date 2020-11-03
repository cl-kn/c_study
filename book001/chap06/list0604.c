#include <stdio.h>

//***************************************************
/**
 * 関数内で関数を呼び出す関数
 */
//***************************************************

/* 関数プロトタイプ宣言 */
int max2(int, int);
int max4(int, int, int, int);

int main(void)
{
    int a, b, c, d;

    printf("四つの整数を入力してください\n");
    printf("一つ目 >> ");
    scanf("%d", &a);
    printf("二つ目 >> ");
    scanf("%d", &b);
    printf("三つ目 >> ");
    scanf("%d", &c);
    printf("四つ目 >> ");
    scanf("%d", &d);

    printf("最大値：%d", max4(a, b, c, d));

    return 0;
}

int max2(int a, int b)
{
    return (a > b) ? a : b;
}

int max4(int a, int b, int c, int d)
{
    return max2(max2(a, b), max2(c, d));
}
