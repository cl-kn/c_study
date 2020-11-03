#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int j;

    printf("整数を入力してください > ");
    scanf("%d", &j);

    printf("%d の絶対値は %d です。\n", j, abs(j));

    return 0;
}

// abs()・・・絶対値を求める