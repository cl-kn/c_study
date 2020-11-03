//***************************************************
/** 乱数生成（種固定） */
//***************************************************

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int retry;
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
rand()関数：<stdlib.h>
・0 以上 RAND_MAX 以下の範囲の擬似乱数整数列を計算する
・戻り値：疑似乱数整数

乱数生成の際の種が固定されているので、何度プログラムを実行しても同じ乱数値となる
*/