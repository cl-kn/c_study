//***************************************************
/** 単純記憶トレーニング（英字記憶１：大文字のみ） */
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

    int i, stage;
    int level;
    int success;
    clock_t start, end;
    const char ltr[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
                       "abcdefghijklmnopqrstuvwxyz"; //英大文字、小文字

    srand(time(NULL));
    printf("英字記憶トレーニング");

    do
    {
        printf("挑戦するレベル（%d ～ %d）：", MIN_LEVEL, MAX_LEVEL);
        scanf("%d", &level);
    } while (level < MIN_LEVEL || level > MAX_LEVEL);

    printf("%d桁の数値を記憶\n", level);

    start = clock();

    for (stage = 0; stage < MAX_STAGE; stage++)
    {
        char mStr[MAX_LEVEL + 1];
        char inStr[MAX_LEVEL * 2];

        for (i = 0; i < level; i++)
        {
            mStr[i] = ltr[rand() % strlen(ltr)];
            mStr[level] = '\0';
        }

        printf("%s", mStr);
        fflush(stdout);
        sleep(125 * level);

        printf("\r%*s\r英文字を入力せよ：", level, "");
        scanf("%s", inStr);

        //正誤判定
        if (strcmp(mStr, inStr) != 0)
        {
            printf("不正解\n");
        }
        else
        {
            printf("正解！！\n");
            success++;
        }
    }

    end = clock();
    printf("%d回中%d回正解\n", MAX_STAGE, success);
    printf("経過時間：%1.f秒", (double)(end - start) / CLOCKS_PER_SEC);

    return 0;
}

/*
「改行、空白、タブなどを挟む文字列リテラルは、連結されて扱われる」
例：
char str[] = "Corgi"
             "Dog";

"CorgiDog" として扱われる

「文字列の扱い方」

const char upper[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
const char lower[] = "abcdefghijklmnopqrstuvwxyz";

上記の配列を用意し、添え字にアクセスする方法

*/