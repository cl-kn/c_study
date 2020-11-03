//***************************************************
/** sprintf(char *str , const char *format, ...)
 * 動作：書式に従い、出力を引数の配列に格納する
 * 引数：
 * char *str 変換した出力を格納する文字列
 * const char *format 書式指定文字列
 * ... 可変個引数（これを書式に従い変換する）
 * 戻り値：
 * 成功 strに格納した文字数
 * 失敗 EOF
 */
//***************************************************

#include <stdio.h>

int main(void)
{
    int i;
    char str[100];
    char str1[] = "shiba";
    char str2[] = "corgi";
    char str3[] = "husky";

    sprintf(str, "%s + %s + %s", str1, str2, str3);
    puts(str);

    return 0;
}