//***************************************************
/** 構造体と構造体を引数にとる関数 */
//***************************************************

#include <stdio.h>
#include <string.h>
#define CHAR_LEN 64

// 構造体の定義
// typedef宣言により、Dogが型名として使える
typedef struct dog
{
    /* data */
    char name[CHAR_LEN];  // 名前
    char breed[CHAR_LEN]; //犬種
    char color[CHAR_LEN]; //毛の色
    float weight;         //体重
}Dog;

// 犬の体重が20kgより大きければ、15kgまで減量
void change_weight(Dog *dog)
{
    if (dog->weight > 20)
    {
        dog->weight = 15;
    }
}

int main(void)
{
    Dog pochi = {"ポチ", "柴犬", "薄茶", 25};

    change_weight(&pochi);

    printf("名前：%s\n", pochi.name);
    printf("犬種：%s\n", pochi.breed);
    printf("毛の色：%s色\n", pochi.color);
    printf("体重：%.1fkg\n", pochi.weight);

    return 0;
}

/*
「->」 アロー演算子
[.]演算子と[->]演算子は、メンバアクセス演算子という
 */