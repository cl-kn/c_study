//***************************************************
/** プログラムメモリ【書き換えできないメモリ領域とは】
 * https://monozukuri-c.com/langc-program-memory/
 * 11/13
 */
//***************************************************

#include <stdio.h>

int main(void)
{
    //const定数
    const int num = 100;

    //文字列リテラルへのポインタを用意
    char *str = "Corgi";

    return 0;
}

/**「プログラムメモリ」「関数・定数」「R」「大サイズ」「関数・定数が配置」
 *
 * 配置されるもの＊＊＊＊＊＊＊＊＊＊＊＊＊
 *・const定数＝＝書き換え不可
 *・文字列リテラル
*/