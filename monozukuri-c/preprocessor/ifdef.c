//***************************************************
/** ifdef 機能 「条件コンパイル」
 *
 * 11/5
 * https://monozukuri-c.com/langc-ifdef/
 */
//***************************************************

#include <stdio.h>

#define DEBUG_FLG (0)

int main(void)
{
// #if ～ #endif---------------------------------------
#if 1
    printf("HELL"); //カットされる処理
#endif
    printf("DOG!!\n");

// #define と、#if ～ #elseの組み合わせ------------------------------
#if DEBUG_FLG
    printf("Hello"); // (1) で実行
#else
    printf("World\n");     // (0)で実行
#endif

//#ifdef ---------------------------------------
#ifdef DEBUG_FLG
    printf("ifdef on\n"); // DEBUG_FLGmacro有効
#else
    printf("ifdef off\n"); // DEBUG_FLGmacro無効
#endif

    //#ifndef 「define定義がされていなければ」

    return 0;
}

/** ifdef 機能「条件コンパイル」
 * ・プログラムの処理の一部を、実行する、しないに切り替えられる機能
 * ・ネストが出来る（コメントアウトでは出来ない）
 *
 *
*/