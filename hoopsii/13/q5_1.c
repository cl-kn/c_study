#include <stdio.h>

//***************************************************
/**
 * 第13回 ポインタ
 * 練習問題：
 * (1) 配列(int, double, char)を各々5個用意し、それぞれの配列のアドレスの変化の様子を出力
 */
//***************************************************

int main(void)
{
    int int_array[5], *p_int, i;
    double double_array[5], *p_double;
    char char_array[5], *p_char;

    p_int = int_array;
    p_double = double_array;
    p_char = char_array;

    for (i = 0; i < 5; i++)
    {
        printf("p_int[%d]_address = %d\n", i, p_int + i);
    }
    for (i = 0; i < 5; i++)
    {
        printf("p_double[%d]_address = %d\n", i, p_double + i);
    }
    for (i = 0; i < 5; i++)
    {
        printf("p_char[%d]_address = %d\n", i, p_char + i);
    }

    return 0;
}