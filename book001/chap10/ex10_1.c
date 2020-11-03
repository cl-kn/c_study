//***************************************************
/** 演習１０－１
 * void adjust_point(int *n){ }において、
 * n < 0 なら0に更新し、100 < nなら100に更新
 * 値が0 ～ 100ならば何もしない。
 */
//***************************************************

#include <stdio.h>

void adjust_point(int *);

int main(void)
{
    int num;
    printf("値を調整します。整数を入力してください。\n");
    scanf("%d", &num);
    adjust_point(&num);

    printf("値：%d", num);

    return 0;
}

void adjust_point(int *n)
{
    if (*n < 0)
    {
        *n = 0;
    }
    else if (100 < *n)
    {
        *n = 100;
    }
}