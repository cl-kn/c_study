//***************************************************
/** プラスワントレーニング４
 * 総合改良版
 * MAX_RECORDの値によって記憶するステージ数を制限する
 * MAX_RECORD数を超えるステージを実行した場合、直近のステージ数をMAX_RECORDの数だけのみ記録する
 */
//***************************************************

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

#define LEVEL_MIN 2  //最小レベル（数値の個数）
#define LEVEL_MAX 5  //最大レベル（数値の個数）
#define MAX_RECORD 3 //ポイントを記憶するステージ数

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
    int i, j, stage, stage2;
    int level;
    int success;
    int point[MAX_RECORD];
    int retry;
    clock_t start, end;

    srand(time(NULL));
    puts("数値を記憶し、１を加えた値を入力して下さい");

    do
    {
        printf("挑戦レベル「%d ～ %d」\n>> ", LEVEL_MIN, LEVEL_MAX);
        scanf("%d", &level);
    } while (level < 0 || level > LEVEL_MAX);

    success = stage = 0; //成功数
    start = clock();     //計測開始

    // 処理部分
    do
    {
        int no[LEVEL_MAX];       //記憶する数
        int in_num[LEVEL_MAX];   //読み込んだ値
        int correct_answers = 0; //このステージでの成功数

        printf("\n第%dステージ開始！！\n", stage + 1);

        for (i = 0; i < level; i++)
        {
            no[i] = rand() % 90 + 10; //１０～９９の乱数を生成
            printf("%d ", no[i]);     //乱数を表示
        }
        fflush(stdout);

        //解答の瞬間表示処理
        sleep(300 * level);
        printf("\r%*s\r", 3 * level, "");
        fflush(stdout);

        //解答を読み込む処理
        for (i = 0; i < level; i++)
        {
            printf("%d番目の数 >> ", i + 1);
            scanf("%d", &in_num[i]);
        }

        //正誤判定・表示
        for (i = 0; i < level; i++)
        {
            if (in_num[i] != no[i] + 1)
            {
                printf("× ");
            }
            else
            {
                printf("〇 ");
                correct_answers++;
            }
        }

        putchar('\n');

        //正解を表示
        for (i = 0; i < level; i++)
        {
            printf("%2d ", no[i]);
        }
        printf("… %d個正解！\n", correct_answers);

        //★として表示する用のポイント
        point[stage++ % MAX_RECORD] = correct_answers;
        success += correct_answers;

        printf(" 続けますか？（Yes … 1 / No … 0）\n>> ");
        scanf("%d", &retry);

    } while (retry == 1);

    end = clock();

    printf("\n-----------------成績-----------------\n");
    stage2 = stage - MAX_RECORD; // 試行回数が10未満の時に、 stage2 < 0

    if (stage2 < 0)
    {
        stage2 = 0;
    }

    //ステージ毎の正解数を★で表示する
    for (i = level; i >= 1; i--)
    {
        for (j = stage2; j < stage; j++)
        {
            if (point[j % MAX_RECORD] >= i)
            {
                printf(" ★ ");
            }
            else
            {
                printf("    ");
            }
        }
        putchar('\n');
    }

    printf("----------------------------------------------\n");

    for (j = stage2; j < stage; j++)
    {
        printf(" %02d ", j + 1);
    }
    putchar('\n');

    printf("%d個中%d個正解しました。\n", level * stage, success);
    printf("経過時間：%1.f秒", (double)(end - start) / CLOCKS_PER_SEC);

    return 0;
}