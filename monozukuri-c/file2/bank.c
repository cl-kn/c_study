#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bank.h"

#define D_ACCOUNT_NAMESIZA (64)

typedef struct
{
    char name[D_ACCOUNT_NAMESIZA]; //登録氏名
    unsigned short pincode;        //暗証番号
    unsigned long balance;         //残金残高

} S_BANK_ACCOUNT;

H_CASHCARD creatBankAccount(const char *name, unsigned short pincode)
{
    S_BANK_ACCOUNT *pAccount = NULL;

    if (name == NULL)
    {
        return NULL;
    }

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