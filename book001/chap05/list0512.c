#include <stdio.h>
#define NUM 80

//***************************************************
/**
 * 点数を読み込み、分布を表示
 * ※配列の要素を多めに設定し、先頭部分を利用する
 */
//***************************************************

int main(void)
{
    int i, j;
    int num;                  /* 実際の人数 */
    int score[NUM];           /* 点数 */
    int dispersing[11] = {0}; /* 分布 */

    printf("人数を入力して下さい：");

    //
    do
    {
        scanf("%d", &num);
        if (num < 1 || num > NUM)
        {
            printf("1 ～ %dで入力して下さい：", NUM);
        }
    } while (num < 1 || num > NUM);

    printf("%d人の点数を入力して下さい\n", num);

    for (i = 0; i < num; i++)
    {
        printf("%2d番：", i + 1);

        do
        {
            scanf("%d", &score[i]);
            if (score[i] < 0 || score[i] > 100)
            {
                printf("\a0 ～ 100で入力して下さい：");
            }
        } while (score[i] < 0 || score[i] > 100);

        //整数 / 整数で小数部が切り捨てられるので、各々の分布域にインクリする。
        dispersing[score[i] / 10]++;
    }

    printf("\n--------分布グラフ--------");
    printf("\n      100 :");

    for (j = 0; j < dispersing[10]; j++)
    {
        putchar('*');
    }
    putchar('\n');

    for (i = 9; i >= 0; i--)
    {
        printf("%3d ～ %3d：", i * 10, i * 10 + 9);
        for (j = 0; j < dispersing[i]; j++)
        {
            putchar('*');
        }
        putchar('\n');
    }
    return 0;
}