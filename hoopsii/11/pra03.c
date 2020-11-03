#include <stdio.h>
#include <string.h>

//***************************************************
/**
 * 例題３ strcoy()関数
 * 値のコピー（書き換え）
 */
//***************************************************

int main(void)
{
    char str1[30] = "AAAAAA";
    char str2[30] = "BBBBBB";
    char str3[30] = "CCCCCC";

    printf("%s\n", str1); // AAAAAA

    strcpy(str1, str2);
    printf("%s\n", str1); // BBBBBB

    strcpy(str2, str3);
    printf("%s\n", str2); // CCCCCC

    strcpy(str3, str1);
    printf("%s\n", str3); // BBBBBB

    return 0;
}