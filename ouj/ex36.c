#include <stdio.h>
int main(void)
{
    int x, y;
    int max;

    printf("整数を２つ入力して下さい。\n");
    printf("１つ目 ＞");
    scanf("%d", &x);
    printf("１つ目 ＞");
    scanf("%d", &y);

    max = (x >= y ? x : y);// 「?:」 条件演算子

    if (x == y) {
        printf("同値です。");
    }else{
        printf("大きい方は %d です。", max);
    }

    return 0;
}