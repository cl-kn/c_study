#include <stdio.h>

//***************************************************
/**
 * 第14回：構造体
 * 例題１：構造体の作成
 */
//***************************************************

struct STUDENT
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

    // 構造体の初期化
    struct STUDENT students[3] =
        {
            {1, "ポチ", 3, 'A'}, // char型のリテラルは '' で囲まれた1文字
            {2, "タマ", 3, 'B'},
            {3, "シロ", 3, 'C'},
        };

    for (i = 0; i < 3; i++)
    {
        printf("%7d%15s%5d%10c\n", students[i].no, students[i].name, students[i].s_year, students[i].s_class);
    }

    return 0;
}