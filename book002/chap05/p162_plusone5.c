//***************************************************
/** プラスワントレーニング５（任意の桁の数値にプラス１したものを答える）
 * 総合改良版
 * トレーニング数可変版、動的領域確保の利用
 */
//***************************************************

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

#define LEVEL_MIN 2 //最小レベル（数値の個数）
#define LEVEL_MAX 5 //最大レベル（数値の個数）

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
    int max_stage; //ステージ試行回数
    int level;
    int *score; // 全ステージの正解数
    int success;
    int point[max_stage];
    clock_t start, end;

    srand(time(NULL));
    puts("数値を記憶し、１を加えた値を入力して下さい");

    do
    {
        printf("挑戦レベル「%d ～ %d」\n>> ", LEVEL_MIN, LEVEL_MAX);
        scanf("%d", &level);
    } while (level < 0 || level > LEVEL_MAX);

    do
    {
        printf("トレーニング回数：");
        scanf("%d", &max_stage);
    } while (max_stage <= 0);

    score = calloc(max_stage, sizeof(int)); //領域確保

    success = 0;     //成功数
    start = clock(); //計測開始

    // 処理
    for (stage = 0; stage < max_stage; stage++)
    {
        int no[LEVEL_MAX];       //記憶する数
        int in_num[LEVEL_MAX];   //読み込んだ値
        int correct_answers = 0; //このステージでの成功数

        printf("\n第%dステージ開始\n", stage + 1);

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
        printf("… %d個正解\n", correct_answers);

        //★として表示する用のポイント
        point[stage++ % max_stage] = correct_answers;
        score[stage] = correct_answers;
        success += correct_answers;
    }

    end = clock();

    printf("----------------------------------------------\n");

    //ステージ毎の正解数を★で表示する
    for (i = level; i >= 1; i--)
    {
        for (j = stage2; j < stage; j++)
        {
            if (point[j % max_stage] >= i)
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

    printf("%d個中%d個正解しました。\n", level * max_stage, success);

    for (stage = 0; stage < max_stage; stage++)
    {
        printf("第%2dステージ：%d\n", stage + 1, score[stage]);
    }
    putchar('\n');

    printf("経過時間：%1.f秒", (double)(end - start) / CLOCKS_PER_SEC);

    free(score);
    return 0;
}