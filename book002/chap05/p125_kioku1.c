//***************************************************
/** 単純記憶トレーニング（4桁の数値を記録） */
//***************************************************

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define MAX_STAGE 5

// xミリ経過を待つ
int sleep(unsigned long x)
{
    clock_t c1 = clock(), c2;

    do
    {
        if ((c2 = clock()) == (clock_t)-1)
        {
            return 0;
        }
    } while (1000.0 * (c2 - c1) / CLOCKS_PER_SEC < x);
    return 1;
}

int main(void)
{
    int stage;       //試行数
    int success = 0; //正解数
    clock_t start, end;

    srand(time(NULL));

    printf("4桁の数値を記憶せよ\n");
    start = clock();

    for (stage = 0; stage < MAX_STAGE; stage++)
    {
        int inputNum;
        int no = rand() % 9000 + 1000;

        printf("%d", no); //数値を表示
        fflush(stdout);
        sleep(500); //0.5秒のみ表示

        printf("\r数値を入力せよ\n\n");
        fflush(stdout);
        scanf("%d", &inputNum);

        // 正誤判定
        if (inputNum != no)
        {
            printf("不正解\n");
        }
        else
        {
            printf("正解！！\n");
            success++; //正解数をインクリ
        }
    }

    end = clock();

    printf("%d回中%d回正解\n", MAX_STAGE, success);
    printf("経過時間：%1.f秒", (double)(end - start) / CLOCKS_PER_SEC);

    return 0;
}