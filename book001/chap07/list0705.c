//***************************************************
/** 配列の要素数を求める
 * sizeof()演算子の利用
*
*/
//**************************************************

#include <stdio.h>

int main(void)
{
    int i_arr[200];
    double d_arr[500];

    int i_arr_size = sizeof(i_arr);
    double d_arr_size = sizeof(d_arr);

    printf("配列 i_arr[200] の型サイズ：%u\n", sizeof(i_arr_size));
    printf("配列 d_arr[500] の型サイズ：%u\n", sizeof(d_arr_size));

    printf("**************************************************\n");

    printf("配列 i_arr[200] の要素数：%u\n", (unsigned)(sizeof(i_arr) / sizeof(i_arr[0])));
    printf("配列 d_arr[500] の要素数：%u\n", (unsigned)(sizeof(d_arr) / sizeof(d_arr[0])));

    return 0;
}