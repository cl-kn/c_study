//***************************************************
/**「プログラム・静的・スタック・ヒープメモリを知ろう」
 * https://monozukuri-c.com/langc-memory/
 * 11/13
 */
//***************************************************

#include <stdio.h>

int main(void)
{
    return 0;
}

/**
 * 「プログラムメモリ」「関数・定数」「R」「大サイズ」「関数や定数」
 * 「スタックメモリ」「変数」「R/W」「小サイズ」「関数内で定義した変数」
 * 「静的メモリ」「」「R/W」「中サイズ」「関数外で定義した変数」
 * 「動的メモリ」「」「R/W」「大サイズ」「メモリ確保関数で取得」
 *
 *
*/