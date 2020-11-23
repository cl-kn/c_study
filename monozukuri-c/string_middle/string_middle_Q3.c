//***************************************************
/** ポインタを使った文字列の扱い方と注意点
 * https://monozukuri-c.com/langc-string-middle/
 * 11/19 , 11/23
 * 課題３
 * 関数：reverse
 * 引数：
 * 第1：char * str (変換する文字列)
 * 戻り値：正常0 異常-1
 * 仕様：第1引数で指定された文字列の順番を前後逆転する
 */
//***************************************************

#include <stdio.h>
#include <string.h>

int reverse(char *str)
{
    int i = 0, j;
    char temp;

    //エラーチェック
    if (str == NULL)
    {
        return -1;
    }

    while (i < strlen(str))
    {
        for (j = strlen(str) - 1; j > 0; j--)
        {
            if (i == j) {
                break;
            }

            temp = str[i];
            str[i] = str[j];
            str[j] = temp;
            i++;
        }
        break;

        // for (j = 0; j < strlen(str); j++)
        // {
        //     temp = str[i];
        //     str[i] = str[j];
        //     str[i] = temp;
        // }
    }

    return 0;
}

int reverse_ans(char *str)
{

    char *pEnd = str;
    char tmp;
    int i;

    //文字列終端へのポインタ取得
    for (i = 0; i < strlen(str) - 1; i++)
    {
        pEnd++;
    }

    //前後の入れ替え
    while (str < pEnd)
    {
        tmp = *str;
        *str = *pEnd;
        *pEnd = tmp;

        str++;
        pEnd--;
    }
    return 0;
}

int main(void)
{
    char str[] = "Good Evening!";
    // char str[] = "aiueo";

    reverse(str);
    // reverse_ans(str);

    printf("%s\n", str);

    return 0;
}