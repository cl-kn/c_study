//***************************************************
/** ポインタを使った文字列の扱い方と注意点
 * https://monozukuri-c.com/langc-string-middle/
 * 11/19、11/23
 * 課題１
 * 関数：countCharacter()
 * 引数：
 * 1: char * search_str 検索対象の文字列
 * 2: char count_str カウント対象の文字列
 * 戻り値：int [0以上（正常）] 対象文字の数 [-1] 異常終了
 * 仕様：第１引数で指定された文字列の中から、第２引数で指定した文字の数を数える
 */
//***************************************************

#include <stdio.h>
#include <string.h>

//自作の関数
int countCharacter(char *search_str, char count_str)
{
    int count = 0;

    //解答より追加のエラーチェック
    if (search_str == NULL)
    {
        return -1;
    }

    while (*search_str != '\0')
    {
        if (*search_str == count_str)
        {
            count++;
        }
        search_str++;
    }
    return count;
}

//解答の関数
int countCharacterAnswer(char *search_str, char count_str)
{
    int count = 0;
    int i;
    if (search_str == NULL)
    {
        return -1;
    }

    //文字列全体を順に参照
    for (i = 0; i < strlen(search_str); i++)
    {
        //一致文字をカウント
        if (search_str[i] == count_str)
        {
            count++;
        }
    }
    return count;
}

int main(void)
{
    char sentence[] = "I'm studying programming at a manufacturing C language school."; //検索対象の文字列
    char search_str;                                                                    //検索する文字
    int count_str;                                                                      //一致した文字数

    search_str = 'a';
    count_str = countCharacter(sentence, search_str);
    printf("文字：%c 個数：%d\n", search_str, count_str);

    search_str = 'm';
    count_str = countCharacter(sentence, search_str);
    printf("文字：%c 個数：%d\n", search_str, count_str);

    return 0;
}