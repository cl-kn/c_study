//***************************************************
/** 構造体１
 * サイト：https://monozukuri-c.com/langc-struct/
 * 10月30日
 */
//***************************************************

#include <stdio.h>

typedef unsigned long S32;

//===================「typedef」を利用した構造体の型定義===================
typedef struct
{
    int melon;
    int apple;
    int orange;
} FruitPrice;

typedef struct
{
    int age;
    int height;
    int weight;
} Person;

//===================構造体の型定義===================
struct MachinePrice
{
    int omen15;
    int macX;
    int thinkPad;
    /* data */
};

//Person構造体の情報を出力する
//配列受け取りver
void printPersonData(Person *person)
{
    printf("age = %d\n", person[0].age);
    printf("height = %d\n", person[0].height);
    printf("weight = %d\n", person[0].weight);
}

int main(void)
{
    FruitPrice f_price = {0, 0, 0}; // 全メンバを初期化（3つ目のみ初期化、等は不可）
    FruitPrice f_price2;            //構造体コピー用

    f_price.melon = 1200;
    f_price.apple = 500;
    f_price.orange = 300;

    struct MachinePrice m_price;
    m_price.thinkPad = 180000;
    m_price.omen15 = 200000;
    m_price.macX = 300000;

    printf("%d\n", f_price.melon);

    //構造体情報の一括コピー
    f_price2 = f_price;
    f_price2.melon = 100;
    printf("%d\n", f_price2.melon);

    //===================構造体変数の配列定義===================
    Person persons[3] = {
        //初期化も可能
        {20, 175, 69},
        {31, 165, 50},
        {42, 189, 80},
    };

    //配列とドット演算子でアクセス
    persons[0].age = 25;
    persons[2].weight = 78;

    printPersonData(persons);

    return 0;
}