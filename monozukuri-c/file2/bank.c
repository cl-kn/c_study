#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bank.h"

#define D_ACCOUNT_NAME_SIZA (64)

//銀行口座情報
typedef struct
{
    char name[D_ACCOUNT_NAME_SIZA]; //登録氏名
    unsigned short pincode;                   //暗証番号
    unsigned long balance;                   //残金残高

} S_BANK_ACCOUNT;

//------------------------------------------------------
// 概要：銀行口座の作成
// 引数1：name 登録氏名
// 引数2：pincode 暗証番号
// 戻り値：キャッシュカードハンドル
//
//※ハンドル領域は動的メモリ。
//➀構造体 S_BANK_ACCOUNT をmalloc()でメモリ確保
//➁確保メモリは、口座を初期化した状態
//balance(残金残高)は、0円で初期化する
//------------------------------------------------------

H_CASHCARD creatBankAccount(const char *name, unsigned short pincode)
{
    S_BANK_ACCOUNT *pAccount = NULL;

    if (name == NULL)
    {
        return NULL;
    }

    //口座情報のメモリ領域をヒープメモリに確保
    pAccount = (S_BANK_ACCOUNT *)malloc(sizeof(S_BANK_ACCOUNT));

    if (pAccount == NULL)
    {
        return NULL;
    }

    strcpy(pAccount->name, name);
    pAccount->pincode = pincode;
    pAccount->balance = 0;

    return pAccount;
}

//------------------------------------------------------
//概要：銀行口座の氏名と残金残高を表示する
//      氏名：山田花子 様
//      残高：0 円
//引数1：H_CASHCARD hCard (表示対象のキャッシュカードハンドル)
//戻り値：正常：0
//        異常：-1
//------------------------------------------------------
int printBalance(H_CASHCARD hCard)
{
    S_BANK_ACCOUNT *pAccount = (S_BANK_ACCOUNT *)hCard;

    //カード情報の正当性チェック
    if (pAccount == NULL)
    {
        return -1;
    }

    printf("----------------------------------\n");
    printf("氏名：%s 様\n", pAccount->name);
    printf("残高：%d 円\n", pAccount->balance);

    return 0;
}

//------------------------------------------------------
//概要：銀行口座へのお金の預け入れを行う
//引数1：H_CASHCARD hCard (預け入れ対象のキャッシュカードハンドル)
//引数2：unsigned long money (預け入れする金額)
//戻り値：正常：0
//        異常：-1
//------------------------------------------------------
int depositMoney(H_CASHCARD hCard, unsigned long money)
{
    S_BANK_ACCOUNT *pAccount = (S_BANK_ACCOUNT *)hCard;

    //カード情報の正当性チェック
    if (pAccount == NULL)
    {
        return -1;
    }

    //預入のお金を残高に加算
    pAccount->balance += money;

    return 0;
}

//------------------------------------------------------
//概要：銀行口座からお金の引き出しを行う
//引数1：H_CASHCARD hCard ()
//引数2：unsigned short pincode (暗証番号)
//引数3：unsigned long reqmoney (引き出し希望金額(円))
//戻り値 int
//       引き出した金額：0以上
//       その他の異常：-1
//       暗証番号不一致：-2
//       残高不足：-3
//------------------------------------------------------
int withdrawalMoney(H_CASHCARD hCard, unsigned short pincode, unsigned long reqmoney)
{
    S_BANK_ACCOUNT *pAccount = (S_BANK_ACCOUNT *)hCard;

    //カード情報の正当性チェック
    if (pAccount == NULL)
    {
        return -1;
    }

    //暗証番号確認
    if (pincode != pAccount->pincode)
    {
        return -2;
    }

    //残高確認
    if (reqmoney > pAccount->balance)
    {
        return -3;
    }

    //残高から減算
    pAccount->balance -= reqmoney;

    return reqmoney;
}

/**------------------------------------------------------
 * 概要：銀行口座の破棄を行う
 * 引数1：H_CASHCARD hCard (破棄対象のキャッシュカードハンドル)
 * 引数2：unsigned short pincode (暗証番号)
 * 戻り値：int
 *         正常：0
 *         その他の異常：-1
 *         暗証番号不一致：-2
 * ※生成で動的メモリにハンドルを割り付けたので、破棄で解放する
*/

int destroyBankAccount(H_CASHCARD hCard, unsigned short pincode)
{
    S_BANK_ACCOUNT *pAccount = (S_BANK_ACCOUNT *)hCard;

    //カード情報の正当性チェック
    if (pAccount == NULL)
    {
        return -1;
    }

    //暗証番号確認
    if (pincode != pAccount->pincode)
    {
        return -2;
    }

    //口座情報を破棄
    free(pAccount);

    return 0;
}