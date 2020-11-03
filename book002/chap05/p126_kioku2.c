//***************************************************
/** 単純記憶トレーニング（数値を記録：レベル＝桁数の設定付き） */
//***************************************************

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STAGE 5  //最大試行数
#define MAX_LEVEL 20 //最大レベル桁数
#define MIN_LEVEL 3  //最小レベル桁数

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
    int i, stage;    //試行数
    int success = 0; //正解数
    // int digit;       //桁数
    int level; //レベル（任意の桁数）
    clock_t start, end;

    srand(time(NULL));

    printf("数値記憶トレーニング\n");

    //レベルの設定入力
    do
    {
        printf("挑戦するレベル(%d～%d)\n>> ", MIN_LEVEL, MAX_LEVEL);
        scanf("%d", &level);

    } while (level < MIN_LEVEL || level > MAX_LEVEL);

    printf("%d桁の数値を記憶\n", level);

    start = clock();

    for (stage = 0; stage < MAX_STAGE; stage++)
    {
        // int inputNum;           //入力値
        char answer[MAX_LEVEL + 1]; //解答する数値の並び
        char digits[MAX_LEVEL * 2]; //読み込んだ数値の並び

        answer[0] = '1' + rand() % 9; //先頭文字１～９を決定する

        for (i = 0; i < level; i++)
        {
            answer[i] = '0' + rand() % 10;
            answer[level] = '\0';
        }

        printf("%s", answer); //数値を表示
        fflush(stdout);
        sleep(125 * level); //解答表示時間：125 × level秒

        printf("\r%*s\r数値を入力せよ：", level, "");
        // printf("\r数値を入力せよ："); // 正解値の後尾部分が残る場合がある
        // fflush(stdout);
        scanf("%s", digits);

        // 正誤判定
        if (strcmp(answer,digits) != 0)
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

/*
printf("\r%*s\r数値を入力せよ：", level, "");

１．[\r]でカーソルを先頭に戻す
２．空白文字をlevel個表示
３．カーソルを先頭に戻す

*/