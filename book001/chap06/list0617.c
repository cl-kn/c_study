//***************************************************
/** 識別子の有効範囲を確認する
 * 「識別子」変数や関数に与えられた名前
*/
//***************************************************

#include <stdio.h>

int x = 75;

void print_x(void)
{
    printf("x = %d\n", x);
}

int main(void)
{
    int i, x = 100;
    print_x();

    for (i = 0; i < 5; i++)
    {
        printf("x = %d\n", x);
        x += 1;
    }

    printf("x = %d\n", x);
    print_x();
    return 0;
}