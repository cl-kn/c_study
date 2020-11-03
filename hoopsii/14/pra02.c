#include <stdio.h>

//***************************************************
/**
 * 第14回：構造体
 * 例題２：アロー演算子を用いる
 */
//***************************************************

//構造体の型宣言
struct OLD
{
    int no;
    char *name;
    int s_year;
    char s_class;
};

int main(void)
{
    int i = 0;
    printf("学籍番号\t 名前\t学年\tクラス\n");

    //構造体の初期化
    struct OLD old[3] =
        {
            {1, "ポチ", 3, 'A'},
            {2, "タマ", 3, 'A'},
            {3, "シロ", 3, 'A'},
        };

    struct OLD *p; //構造体のポインタ宣言
    p = old;       //ポインタ[p]に構造体[old]の先頭アドレスを代入

    for (i = 0; i < 3; i++)
    {
        //結果の出力
        printf("%7d%15s%5d%10c\n", (p + i)->no, (p + i)->name, (p + i)->s_year, (p + i)->s_class);
    }

    return 0;
}