#include <stdio.h>
#include "Q2_fruit2.h"

static void main_calcFruit(void);

//------------------------------------------------
//  概要：メイン処理
//  引数：なし
//  戻り値：0 正常
//------------------------------------------------
int main(void)
{
    fruit_printFruitInfo();

    main_calcFruit();

    return 0;
}

//-------------------------------------------------
//  概要：フルーツ購入価格の算出表示
//  引  数：なし
//  戻り値：なし
//-------------------------------------------------
static void main_calcFruit(void)
{
    long allPrice = 0;

    allPrice += fruit_getPriceFruit(E_FRUIT_ID_PEACH, 3);  //  桃3個
    allPrice += fruit_getPriceFruit(E_FRUIT_ID_BANANA, 5); //  バナナ5本

    printf("購入価格：%d", allPrice);
}