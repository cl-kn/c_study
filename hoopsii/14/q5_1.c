#include <stdio.h>

//***************************************************
/**
 * 第１４回：構造体
 * 問題５：表を構造体に
 */
//***************************************************

//構造体の宣言：給与
struct SALARY
{
    int salary_april;
    int salary_may;
    int salary_june;
};

//構造体の宣言：社員
struct MEMBER
{
    int num;             //社員番号
    char *name;          //氏名
    char *department;    //部署
    char *position;      //役職
    struct SALARY money; //構造体の入れ子
};

void output(struct MEMBER members[]);

int main(void)
{
    int i = 0;
    // printf("社員番号\t氏名\t部署\t役職\n\n");

    //構造体の初期化
    struct MEMBER members[] =
        {
            {1, "ポチ", "総務", "部長", {43500, 44000, 43750}},
            {2, "タマ", "営業", "部長", {45000, 47000, 46000}},
            {3, "タロ", "技術", "課長", {34000, 35000, 45000}},
            {4, "ジロ", "総務", "主任", {30000, 29000, 31000}},
            {5, "ゴロ", "技術", "係長", {26000, 29000, 28000}},
        };

    //構造体のポインタ宣言
    struct MEMBER *p;
    //ポインタpに構造体membersの先頭アドレスを参照渡しする
    p = members;

    // output関数へ構造体pの先頭アドレスを代入
    output(p);

    return 0;
}

void output(struct MEMBER *p)
{
    int i = 0;

    while (p->num < 6)
    {
        printf("%d %s %s %s %d %d %d\n",

               p->num,
               p->name,
               p->department,
               p->position,
               p->money.salary_april,
               p->money.salary_may,
               p->money.salary_june);
        p++;
    }

    // for (i = 0; i < 5; i++)
    // {
    //     printf("%7d%15s%10s%10s\n",
    //            (p + i)->num,
    //            (p + i)->name,
    //            (p + i)->department,
    //            (p + i)->position);
    // }
}