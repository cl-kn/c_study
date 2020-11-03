#include <stdio.h>
// #define NUM 5
// #define prt_max(max) printf("最高点：%d点\n", max)
// #define prt_min(min) printf("最低点：%d点\n", min)

//***************************************************
/**
 * 点数の最高点と最低点を表示
 */
//***************************************************

const int NUM = 3;

int main(void)
{
    int i;
    int score[NUM];
    int max, min;

    printf("5人の点数を入力してください\n");

    for (i = 0; i < NUM; i++)
    {
        printf("%d番目：", i + 1);
        scanf("%d", &score[i]);
    }

    min = max = score[0];
    for (i = 1; i < NUM; i++)
    {
        if (score[i] > max)
        {
            max = score[i];
        }
        if (score[i] < min)
        {
            min = score[i];
        }
    }

    // prt_max(max);
    // prt_min(min);
    printf("最高点：%d点\n", max);
    printf("最低点：%d点", min);

    return 0;
}