//***************************************************
/** ポインタを使った文字列の扱い方と注意点
 * https://monozukuri-c.com/langc-string-middle/
 * 11/19 , 11/23
 * 課題２
 * 関数：toUpper
 * 引数：
 * 第１：char * str (変換する文字列)
 * 戻り値：
 * int 0：正常終了 -1：異常終了
 * 仕様：第1引数で指定された文字列において、英小文字を英大文字に変換する。英小文字以外の文字は無変換
 */
//***************************************************

#include <stdio.h>
#include <string.h>

int toUpper(char *str)
{
    int i, offset;

    if (str == NULL)
    {
        return -1;
    }

    for (i = 0; i < strlen(str); i++)
    {
        // offset = str;
        // if (str >= 97) {

        // }

        //解答より、英小文字判定 a:97 , z:122
        if (str[i] >= 'a' && str[i] <= 'z')
        {
            //英小文字と英大文字の差分を引く (差分:32)
            str[i] -= 'a' - 'A';
        }
    }
    return 0;
}

//ex.
int toLower(char *str)
{
    int i;

    if (str == NULL)
    {
        return -1;
    }

    for (i = 0; i < strlen(str); i++)
    {
        if (str[i] >= 'A' && str[i] <= 'Z')
        {
            str[i] += 'a' - 'A';
        }
    }
    return 0;
}

int main(void)
{
    char str[] = "Hello World 2nd!";

    //文字列を大文字に変換
    toUpper(str);

    //文字列表示
    printf("%s\n", str);

    //ex.文字列を小文字に変換
    toLower(str);

    //文字列表示
    printf("%s\n", str);

    return 0;
}