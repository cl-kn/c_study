//***************************************************
/** 暗算 */
//***************************************************

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main(void)
{
    int stage;
    int num1, num2, num3; //加算する数値
    int in;               //入力値
    int n;                //余白の幅
    int time_start, time_end;

    srand(time(NULL));
    printf("暗算トレーニング***スタート***\n");
    time_start = clock();

    for (stage = 0; stage < 2; stage++)
    {
        num1 = 10 + rand() % 90; // １０～９９の乱数を設定
        num2 = 10 + rand() % 90; // １０～９９の乱数を設定
        num3 = 10 + rand() % 90; // １０～９９の乱数を設定

        n = rand() % 17; //１０～１６の乱数を設定（余白）

        printf("%d%*s+%*s%d%*s+%*s%d : ", num1, n, "", n, "", num2, n, "", n, "", num3);

        do
        {
            printf(">> ");
            scanf("%d", &in);
            if (in == num1 + num2 + num3)
            {
                break;
            }
            else
            {
                printf("不正解：答えを再入力して下さい\n>> ");
            }
        } while (1);
    }

    time_end = clock();
    printf("経過時間：%.1f秒", (double)(time_end - time_start) / CLOCKS_PER_SEC);

    return 0;
}

/*
int x = 10;
int n = 4;のとき
printf("%d%*s+" ,x,n); は、
10    +
と出力される。
*/