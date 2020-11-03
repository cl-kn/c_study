//***************************************************
/** 数当てゲーム（入力履歴の保存） */
//***************************************************

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define MAX_STAGE 10 //入力可能回数

int main(void)
{
    int no;                   // 入力値
    int ans;                  //正解値
    int stage = 0;            // 入力回数
    int num[MAX_STAGE];       // 入力履歴値の保存用配列
    const int max_stage = 10; //最大入力回数
    int remain = max_stage;   // 残り何回入力できるか

    srand(time(NULL));
    ans = rand() % 1000; //0から999までの乱数生成

    printf("整数値０～９９９の数当て\n");
    printf("%d\n", ans);
    do
    {
        printf("入力可能回数 %d 回\n", MAX_STAGE - stage);
        scanf("%d", &no);
        remain--;
        num[stage++] = no;

        if (no > ans)
        {
            puts("もっと小さな値");
        }
        else if (no < ans)
        {
            puts("もっと大きな値");
        }

    } while (no != ans && remain < MAX_STAGE);

    if (no != ans)
    {
        printf("入力可能回数を超過\n正解値：%d", ans);
    }
    else
    {
        printf("正解！\n正解値：%d\n入力値：%d\n", ans, no);
        printf("残り入力可能回数：%d 回", remain);

        printf("入力履歴\n");

        for (int i = 0; i < stage; i++)
        {
            //1回目：入力値：入力値と正解値の差 を表示する
            printf("%2d : %4d %+4d\n", i + 1, num[i], num[i] - ans);
        }
    }

    return 0;
}

/*
%+4d について
書式文字列を"%+d"とすると、 + - の符号が付与される

*/