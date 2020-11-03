#include <stdio.h>

//***************************************************
/*
 * 第１４回：構造体
 * 例題４：参照渡し
 */
//***************************************************

//構造体の型宣言
struct STU
{
    int no;
    char *name;
    int s_year;
    char s_class;
};

//関数プロトタイプ宣言
void output(struct STU stu[]);

int main(void)
{
    printf("学籍番号\t名前\t学年\tクラス\n");

    //構造体の初期化
    struct STU stu[3] = {

        {1, "ポチ", 3, 'A'},
        {2, "タマ", 3, 'B'},
        {3, "シロ", 3, 'C'},
    };

    //output()関数へ構造体oldを値渡しする
    output(stu);

    return 0;
}

//引数に構造体を用いた自作関数output
void output(struct STU *p)
{
    int i = 0;
    for (i = 0; i < 3; i++)
    {
        printf("%7d%15s%5d%10c\n", (p + i)->no, (p + i)->name, (p + i)->s_year, (p + i)->s_class);
    }
}