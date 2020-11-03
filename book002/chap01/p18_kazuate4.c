//***************************************************
/** 数当てゲーム（入力回数の制限ver） */
//***************************************************

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main(void)
{
    int no;
    int ans;
    const int max_stage = 10; //最大入力回数
    int remain = max_stage;   // 残り何回入力できるか

    srand(time(NULL));
    ans = rand() % 1000; //0から999までの乱数生成

    printf("０～９９９の整数値を当ててください\n");

    do
    {
        printf("入力可能回数 %d 回\n", remain);
        scanf("%d", &no);
        remain--;

        if (no > ans)
        {
            puts("もっと小さな値です。");
        }
        else if (no < ans)
        {
            puts("もっと大きな値です。");
        }

    } while (no != ans && remain > 0);

    if (no != ans)
    {
        printf("入力可能回数を超えました。\n正解値：%d", ans);
    }
    else
    {
        printf("正解です！\n正解値：%d\n入力値：%d\n", ans, no);
        printf("残り入力可能回数：%d 回", remain);
    }

    return 0;
}