//***************************************************
/** 文字列の比較
 * strcmp()関数
 * <string.h>
 * int strcmp (const char *s1, const char *s2);
 * 内容：文字列s1と文字列s2との比較
 * 戻り値：
 * s1 = s2・・・0
 * s1 > s2・・・正の整数
 * s1 < s2・・・負の整数
 */
//***************************************************

#include <stdio.h>
#include <string.h>

int main(void)

{
    char str1[] = "DOG";
    char str2[256];

    printf(">>");
    scanf("%s", str2);

    int result;

    result = strcmp(str1, str2);

    if (result == 0)
    {
        puts("OK");
    }
    else
    {
        puts("NOT");
    }

    return 0;
}