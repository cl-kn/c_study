#include <stdio.h>
#include "Q2_fruit.h"

#define D_FRUIT_NAMESIZE (32)

typedef struct
{
    char name[D_FRUIT_NAMESIZE]; //  名前
    long price;                  //  価格
} S_FRUIT_INFO;

//------------------------------------------------
//  フルーツテーブル定義
//------------------------------------------------
const static S_FRUIT_INFO gFruitTbl[] =
    {
        {"みかん", 50},
        {"桃", 400},
        {"バナナ", 100},
        {"パイナップル", 250},
};

//------------------------------------------------
//  概要：全フルーツ情報の出力
//  引数：なし
//  戻り値：なし
//------------------------------------------------

void fruit_printFruitInfo(void)
{

    E_FRUIT_KIND_ID i;

    printf("--------------------------------------------\n");

    for (i = 0; i < E_FRUIT_ID_END; i++)
    {
        printf("名前：%-16s\t価格：%5d円\n",
               gFruitTbl[i].name, gFruitTbl[i].price);
    }

    printf("--------------------------------------------\n");
}

//------------------------------------------------
//  概要：フルーツ代金の取得。
//          フルーツIDと個数から代金を算出する
//  引数：id  算出するフルーツID
//          num 個数
//  戻り値：0以上   算出した代金
//          負値    異常時
//------------------------------------------------
long fruit_getPriceFruit(E_FRUIT_KIND_ID id, unsigned short num)
{
    if (id < 0 || id >= E_FRUIT_ID_END)
    {
        return -1;
    }

    return gFruitTbl[id].price * num;
}
