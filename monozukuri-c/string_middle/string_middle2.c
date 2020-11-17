//***************************************************
/** ポインタを使った文字列の扱い方と注意点
 * https://monozukuri-c.com/langc-string-middle/
 * 11/17
 * ～文字列・メモリ制御ライブラリから考察するポインタの使い方～まで
 * 「関数仕様から関数の作りをイメージする」
 */
//***************************************************

#include <stdio.h>

//strlen関数
size_t strlen_my(const char *str)
{
    // int i,count;
    // for (i = 0; i < ; i++) {
    // }

    size_t len = 0;

    while (*str != '\0')
    {
        len++; //文字列長さをカウント
        str++; //ポインタ照準を移動
    }

    return len;
}

int main(void)
{
    char *str = "corgi";
    printf("%d", strlen_my(str));
 
    return 0;
}

/**「文字列制御関数」
 * 
 * strlen [文字列の長さを取得] size_t strlen(const char * str);
 * 
 * 
*/