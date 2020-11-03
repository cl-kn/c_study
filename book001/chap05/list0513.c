#include <stdio.h>
#define NUM 4

//***************************************************
/**
 * 4人の学生の3科目のテスト2回分の合計を求めて表示
 */
//***************************************************

int main(void)
{
    int i, j;
    int score1[NUM][3] = {{91, 63, 78}, {67, 72, 46}, {89, 34, 53}, {32, 54, 34}};
    int score2[NUM][5] = {{97, 67, 82}, {73, 43, 46}, {97, 56, 21}, {85, 46, 35}};
    int sum[NUM][3];

    /*2回分の点数の合計を求める*/
    for (i = 0; i < NUM; i++)
    {
        for (j = 0; j < 3; j++)
        {
            sum[i][j] = score1[i][j] + score2[i][j];
        }
    }

    /*1回目の点数を表示*/
    puts("[1回目の点数]");
    for (i = 0; i < NUM; i++)
    {
        for (j = 0; j < 3; j++)
        {
            printf("%d ", score1[i][j]);
        }
        printf("\n");
    }

    /*2回目の点数を表示*/
    puts("\n[2回目の点数]");
    for (i = 0; i < NUM; i++)
    {
        for (j = 0; j < 3; j++)
        {
            printf("%d ", score2[i][j]);
        }
        printf("\n");
    }

    /*合計点を表示*/
    puts("\n[合計の点数]");
    for (i = 0; i < NUM; i++)
    {
        for (j = 0; j < 3; j++)
        {
            printf("%d ", sum[i][j]);
        }
        printf("\n");
    }

    return 0;
}