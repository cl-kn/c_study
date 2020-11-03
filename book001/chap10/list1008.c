//***************************************************
/** 2つの実数値を交換（誤りプログラム）
 * 型の不一致
*/
//***************************************************

#include <stdio.h>

void swap(int *px, int *py)
{
    int temp = *px;
    *px = *py;
    *py = temp;
}

int main(void)
{
    double x, y;
    printf("値を入力してください。\n");
    printf("x = ");
    scanf("%lf", &x);
    printf("y = ");
    scanf("%lf", &y);

    swap(&x, &y);

    printf("値を昇順に並べ替えました。\n");
    printf("x = %.1f\ny = %.1f", x, y);
    return 0;
}
