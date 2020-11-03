//***************************************************
/** 乱数利用の数当てゲーム */
//***************************************************

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main(void)
{
    int inNum;
    int ans;

    srand(time(NULL));
    ans = rand() % 101; // 乱数の範囲を0 ～ 101に設定

    printf("数当てゲーム：０～１００\n");

    do
    {
        printf(">> ");
        scanf("%d", &inNum);

        if (inNum > ans)
        {
            printf("もっと小さい値です。\n");
        }
        else if (inNum < ans)
        {
            printf("もっと大きい値です。\n");
        }

    } while (inNum != ans);

    printf("正解値：%d\n入力値：%d", ans, inNum);
    printf("当たりです！");

    return 0;
}
