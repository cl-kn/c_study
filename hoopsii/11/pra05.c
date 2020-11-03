#include <stdio.h>
#include <string.h>

//***************************************************
/**
 * 例題５ strlen()関数
 * strlen( )関数は文字列の長さを取得する関数です。
 * strlen(a)は文字列aの長さを取得するという意味になります。
 * 文字列aのところは" "でくくった文字列も記述できます。
 */
//***************************************************

int main(void)
{
    int len;
    char str[256];

    printf("半角英数字を入力してください >> ");
    scanf("%s", str);

    len = strlen(str);

    printf("入力文字 [%s] は %d 文字です。", str, len);

    return 0;
}