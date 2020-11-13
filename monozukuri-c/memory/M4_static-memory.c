//***************************************************
/** 静的メモリ【システムに常駐するメモリの役割と使い方】
 * https://monozukuri-c.com/langc-static-memory/
 * 11/13
 */
//***************************************************

#include <stdio.h>

short gCount = 0;
short gCount2 = 200;
static int static_num = 0;

void count(void)
{
    gCount++;
}
void disp(void)
{
    printf("%d\n", gCount);
}

int main(void)
{
    disp();
    count();
    disp();

    return 0;
}

/**
 * 「静的メモリ」「変数」「R / W」「中サイズ」「関数外で定義した変数が配置」
 *
 * ・グローバル変数が配置されるメモリ
 * ・グローバル変数の初期値は０（※これを前提にPG作成をしないほうが良い）
 *
 * 「外部参照宣言」
 * 別ファイルで定義されている変数を参照する際に使用する宣言。
 *
 * extern データ型 変数名 ※使用時に初期値は設定できない
 *
 * 「static修飾子」
 * ・staticが付与されたグローバル変数は、定義ないファイルからのみ参照可能、外部ファイルからは参照できない
 *
 *
*/