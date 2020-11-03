//***************************************************
/** ポインタを利用した、値の交換 */
//***************************************************

#include <stdio.h>

void change(int *, int *);

int main(void)
{
    int x, y;
    printf("値を交換します。整数を入力してください。\n");
    printf("x = ");
    scanf("%d", &x);
    printf("y = ");
    scanf("%d", &y);

    change(&x, &y);

    printf("値が交換されました。\n");
    printf("x = %d\ny = %d", x, y);

    return 0;
}

// 値を交換する関数
void change(int *p_x, int *p_y)
{
    int temp;
    temp = *p_x;
    *p_x = *p_y;
    *p_y = temp;
}