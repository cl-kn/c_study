#ifndef FRUIT_H
#define FRUIT_H
//------------------------------------------------

//------------------------------------------------
//  マクロ定義(Macro definition)
//------------------------------------------------


//------------------------------------------------
//  型定義(Type definition)
//------------------------------------------------


typedef enum
{
    E_FRUIT_ID_ORANGE = 0,
    E_FRUIT_ID_PEACH,
    E_FRUIT_ID_BANANA,
    E_FRUIT_ID_PINE,
    //------------------------
    E_FRUIT_ID_END, //  番兵
} E_FRUIT_KIND_ID;

//------------------------------------------------
//  プロトタイプ宣言(Prototype declaration)
//------------------------------------------------
void fruit_printFruitInfo(void);
long fruit_getPriceFruit(E_FRUIT_KIND_ID id, unsigned short num);

//------------------------------------------------
#endif