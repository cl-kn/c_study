//***************************************************
/** 乱数生成（種＝現在時刻） */
//***************************************************

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
    int retry;
    srand(time(NULL));
    printf("この処理系では、0 ～ %dの乱数が生成されます。\n", RAND_MAX);

    do
    {
        printf("乱数：%d\n", rand());
        printf("もう一度 1\n終了 0\n");
        scanf("%d", &retry);

    } while (retry == 1);

    return 0;
}

/*
srand()関数：<stdlib.h>
・rand()関数で返される疑似乱数の乱数種（シード）を設定する
・time()関数の戻り値を引数にすればランダムに疑似乱数を発生できる
・引数：seed（乱数種、シード）
 */