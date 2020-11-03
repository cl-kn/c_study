//***************************************************
/** 11-4：文字列の配列 */
//***************************************************

#include <stdio.h>

int main(void)
{
    int i;
    char str[][5] = {"AB", "O", "A"};
    char *p_str[] = {"dog", "cat", "rabbit"};

    for (i = 0; i < 3; i++)
    {
        printf("str[%d] = %s\n", i, str[i]);
    }

    printf("-----------------------------------\n");

    for (i = 0; i < 3; i++)
    {
        printf("p_str[%d] = %s\n", i, p_str[i]);
    }

    return 0;
}










/*

コンパイルエラー
excess elements in char array initializer：1つの変数を初期化する要素が多すぎ

 */