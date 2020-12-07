//***************************************************
/** ハンドルの作り方【オリジナルのハンドルを自作する方法】
 * https://monozukuri-c.com/langc-original-handle/
 * 11/30、12/2
 */
//***************************************************

#include <stdio.h>
#include "bank.h"

int main(void)
{
    H_CASHCARD hCard1 = NULL;
    H_CASHCARD hCard2 = NULL;

    //銀行口座の作成
    //氏名、PINコード
    hCard1 = creatBankAccount("尾崎豊", 0x1876);
    hCard2 = creatBankAccount("緒方尚子", 0x1835);

    //口座情報の表示
    printBalance(hCard1);
    printBalance(hCard2);

    //預け入れ
    depositMoney(hCard1, 1250050);
    depositMoney(hCard2, 15000000);

    //口座情報の表示
    printBalance(hCard1);
    printBalance(hCard2);

    //引き出し
    withdrawalMoney(hCard1, 0x1876, 125000);
    withdrawalMoney(hCard2, 0x1835, 125000);

    //口座情報の表示
    printBalance(hCard1);
    printBalance(hCard2);

    //銀行口座の破棄
    destroyBankAccount(hCard1,0x1876);
    destroyBankAccount(hCard2,0x1835);

    return 0;
}

/**
 * 「ハンドルの考え方～キャッシュカードの仕組みを考える」
 * ・使用ファイル
 * F5_original-handle.c (ハンドルを使用するファイル)
 * bank.h (ヘッダファイル)
 * bank.c (関数ファイル)
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