//***************************************************
/** ハンドルの作り方【オリジナルのハンドルを自作する方法】
 * https://monozukuri-c.com/langc-original-handle/
 * 11/30、12/2
 */
//***************************************************

#include <stdio.h>

int main(void)
{
    return 0;
}

/**
 * 「ハンドルの考え方～キャッシュカードの仕組みを考える」
 * 
 * １：ハンドル（キャッシュカード）で利用できるサービスを考える
 * ２：扱うデータを設定・管理する（登録氏名、暗証番号、残金残高）
 * ３：上記を型として定義する（構造体）
 * 
 * 「例」S_BANK_ACCOUNT構造体の定義
 * 
 * #define D_ACCOUNT_NAMESIZA (64)
 * 
 * typedef struct {
 *      char[D_ACCOUNT_NAMESIZA] name;          //登録氏名
 *      unsigned short pincode; //暗証番号
 *      unsigned long balance;  //残金残高
 * 
 * }S_BANK_ACCOUNT
 * 
 * 
*/