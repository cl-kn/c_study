//***************************************************
/** クイックソート
 * 構造体データの並び替え
 * 参考：https://monozukuri-c.com/langc-funclist-qsort/
 */
//***************************************************

#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    char name[32];
    short age;
    double height;
} S_PERSON;

S_PERSON players[] = {

    {"ラファエル・ナダル", 34, 185.6},
    {"ノバク・ジョコビッチ", 33, 188.1},
    {"ロジャー・フェデラー", 39, 185.4},
    {"錦織圭", 30, 178.2},
};

// 年齢（昇順）
int cmpAscAge(const void *n1, const void *n2)
{
    if (((S_PERSON *)n1)->age > ((S_PERSON *)n2)->age)
    {
        return 1;
    }
    else if (((S_PERSON *)n1)->age < ((S_PERSON *)n2)->age)
    {
        return -1;
    }
    else
    {
        return 0;
    }
}

int main(void)
{
    int i;

    qsort(players, sizeof(players) / sizeof(players[0]), sizeof(S_PERSON), cmpAscAge);

    for (i = 0; i < sizeof(players) / sizeof(players[0]); i++)
    {
        printf("%-24s,%d,%lf \n", players[i].name, players[i].age, players[i].height);
    }

    return 0;
}