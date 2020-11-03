#include <stdio.h>
#define NUM 5

//***************************************************
/**
 * 〇人の点数の合計と平均を求める
 * オブジェクト形式マクロ
 * #define NUM 5
 * 以降の NUM を5に置換する命令
 */
//***************************************************

int main(void)
{
    int i;
    int score[NUM];
    int sum = 0;
    double average = 0;

    printf("5人の点数を入力してください\n");

    for (i = 0; i < NUM; i++)
    {
        printf("点数を入力 ＞＞");
        scanf("%d", &score[i]);
        sum += score[i];
    }

    average = sum / 5;
    printf("合計点 : %d\n", sum);
    printf("平均点 : %.1lf\n", average);

    return 0;
}