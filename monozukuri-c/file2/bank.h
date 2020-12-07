//  多重インクルード防止
#ifndef BANK_H
#define BANK_H
//------------------------------------------------

//------------------------------------------------
//  マクロ定義(Macro definition)
//------------------------------------------------

//------------------------------------------------
//  型定義(Type definition)
//------------------------------------------------
//キャッシュカードハンドル
typedef void *H_CASHCARD; //「H_CASHCARD型」は、void型ポインタ

//------------------------------------------------
//  プロトタイプ定義(Prototype definition)
//------------------------------------------------
H_CASHCARD creatBankAccount(const char *name, unsigned short pincode);
int printBalance(H_CASHCARD hCard);
int depositMoney(H_CASHCARD hCard, unsigned long money);
int withdrawalMoney(H_CASHCARD hCard, unsigned short pincode, unsigned long reqmoney);
int destroyBankAccount(H_CASHCARD hCard, unsigned short pincode);

//------------------------------------------------
#endif