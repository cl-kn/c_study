#include <stdio.h>
#define NUM 5

//***************************************************
/**
 * 最高点を求める
 */
//***************************************************

// 配列の定義
int score[NUM];
// 関数プロトタイプ宣言
int top_value(void);

int main(void)
{
    extern int score[];
    int i;

    printf("%d人の点数を入力して下さい\n", NUM);
    for (i = 0; i < NUM; i++)
    {
        printf("%d番目: ", i + 1);
        scanf("%d", &score[i]);
    }

    printf("最高点 = %d\n", top_value());

    return 0;
}

int top_value(void)
{
    extern int score[];
    int i;
    int max = score[0];

    for (i = 1; i < NUM; i++)
    {
        if (score[i] > max)
        {
            max = score[i];
        }
    }
    return max;
}