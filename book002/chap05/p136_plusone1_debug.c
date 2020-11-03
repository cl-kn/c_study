//***************************************************
/** プラスワントレーニング（任意の桁の数値にプラス１したものを答える）
 * デバッグ用
 */
//***************************************************

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STAGE 3  //最大試行数
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
    int i, stage;         //ステージ数
    int level;            //レベル
    int successNum;       //成功回数
    int score[MAX_STAGE]; //ステージ毎のスコア
    clock_t start, end;   //時間計測開始・終了

    srand(time(NULL));
    puts("プラスワントレーニング");
    puts("2桁の数値を記憶します");
    puts("１を加えた値を入力して下さい");

    //レベル設定
    // do
    // {
    //     printf("挑戦するレベル（%d ～ %d）：", MIN_LEVEL, MAX_LEVEL);
    //     scanf("%d", &level);
    // } while (level < MIN_LEVEL || level > MAX_LEVEL);
    level = 3;

    successNum = 0;  //成功数
    start = clock(); //計測開始

    // MAX_STAGE数分だけ問題を開始する
    for (stage = 0; stage < MAX_STAGE; stage++)
    {
        int ansNum[MAX_LEVEL]; //解答の乱数
        int inNum[MAX_LEVEL];  //読み込み用
        int hit = 0;           //一致した数

        printf("\n「第%dステージ開始」\n", stage + 1);

        for (i = 0; i < level; i++)
        {
            // ansNum[i] = rand() % 90 + 10; //10～99の乱数生成
            ansNum[i] = i + 10;
            printf("%d ", ansNum[i]);
        }

        fflush(stdout);
        sleep(300 * level); // 0.30×level秒待って表示する
        printf("\r%*s\r", 3 * level, "");
        fflush(stdout);

        //解答を受け取る
        for (i = 0; i < level; i++)
        {
            // printf("%d番目の数 >> ", i + 1);
            // scanf("%d", &inNum[i]);
            inNum[i] = i + 11;
        }

        putchar('\n');

        //正誤判定(ansNumに1を加えた数を答える)
        for (i = 0; i < level; i++)
        {
            if (ansNum[i] + 1 == inNum[i])
            {
                printf("〇 ");
                hit++;
            }
            else
            {
                printf("× ");
            }
        }

        putchar('\n');

        for (i = 0; i < level; i++)
        {
            printf("%2d ", ansNum[i]);
        }

        printf("[%d個正解です]\n", hit);
        score[stage] = hit; //正解した個数をステージ毎配列に格納する
        successNum += hit;  //正解した個数の総数をsuccessNumに累計していく
    }

    end = clock();

    printf("%d／%d個正解\n", successNum, level * MAX_STAGE);

    //縦向きグラフ表示ver
    // printf("\n■ □ スコア □ ■\n");
    // printf("--------------------------------\n");
    // for (stage = 0; stage < MAX_STAGE; stage++)
    // {
    //     printf("第%2dステージ：", stage + 1);
    //     for (i = 0; i < score[stage]; i++)
    //     {
    //         printf("★ "); //正解記号
    //     }
    //     putchar('\n');
    // }
    // printf("--------------------------------\n");

    //縦向きグラフ表示ver
    printf("\n■ □ スコア □ ■\n");
    for (i = level; i >= 1; i--)
    {
        for (stage = 0; stage < MAX_STAGE; stage++)
        {
            if (score[stage] >= i)
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
    printf("--------------------------------\n");
    for (stage = 1; stage <= MAX_STAGE; stage++)
    {
        printf(" %02d ", stage);
    }
    putchar('\n');

    //通常表示ver
    // for (stage = 0; stage < MAX_STAGE; stage++)
    // {
    //     printf("第%dステージ：%d\n", stage + 1, score[stage]);
    // }

    printf("経過時間：%1.f秒", (double)(end - start) / CLOCKS_PER_SEC);

    return 0;
}

/*

*/