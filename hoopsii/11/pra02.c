#include <stdio.h>
#include <string.h>

//***************************************************
/**
 * 例題２ strcat()関数
 * 値の連結
 */
//***************************************************

int main(void)
{
    char str1[30] = "AAAAAA";
    char str2[30] = "BBBBBB";
    char str3[30] = "CCCCCC";

    // 連結："AAAAAA" + "BBBBBB"
    strcat(str1, str2);
    printf("%s\n", str1);

    // "BBBBBB" + "CCCCCC"
    strcat(str2, str3);
    printf("%s\n", str2);

    // "AAAAAA" + "BBBBBB" + "CCCCCC"
    strcat(str1, str3);
    printf("%s\n", str1);

    return 0;
}