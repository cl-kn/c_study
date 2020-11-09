//***************************************************
/** 「アロー演算子の使い方【ポインタから構造体を使う】
」
 * https://monozukuri-c.com/langc-pointer-struct/
 * 11/9
 */
//***************************************************

#include <stdio.h>

typedef struct
{
    int corgi; //コーギー
    int shiba; //柴犬

} S_DogId;

int main(void)
{
    S_DogId dogs;
    S_DogId *p_dogs = &dogs;

    dogs.corgi = 1;
    dogs.shiba = 2;

    printf("corgi id = %d,shiba id = %d\n", dogs.corgi, dogs.shiba);

    //ポインタによるメンバへのアクセス -> の使用
    p_dogs->corgi = 11;
    p_dogs->shiba = 12;

    printf("corgi id = %d,shiba id = %d\n", p_dogs->corgi, p_dogs->shiba);

    return 0;
}

/**「アロー演算子」
 * ポインタ変数 -> 構造体メンバ名
 *
 * 【例】p_dogs -> corgi
 * 【意味】構造体を参照しているポインタ(p_dogs)から、構造体メンバ(corgi)へアクセスする
 *
*/