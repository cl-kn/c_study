#include <stdio.h>
#define NUM 5

//***************************************************
/**
 * 点数の最高点と最低点を表示
 * （配列の受け渡し）
 */
//***************************************************

void score_max_min(int[]);

int main(void)
{
    int score[NUM];
    score_max_min(score[NUM]);
    return 0;
}

void score_max_min(int array[])
{
    int i;
    int max, min;

    printf("5人の点数を入力してください\n");

    for (i = 0; i < NUM; i++)
    {
        printf("%d番目：", i + 1);
        scanf("%d", &array[i]);
    }

    min = max = array[0];
    for (i = 1; i < NUM; i++)
    {
        if (array[i] > max)
        {
            max = array[i];
        }
        if (array[i] < min)
        {
            min = array[i];
        }
    }

    printf("最大値：%d\n", max);
    printf("最小値：%d\n", min);
}