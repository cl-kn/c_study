//***************************************************
/** 6-14：逐次探索（番兵法） */
//***************************************************

#include <stdio.h>
#define NUMBER 5
#define FAILED -1

int search(int[], int, int);

int main(void)
{
    int i, ky, idx;
    int vx[NUMBER + 1]; /* 番兵用に要素を1つ多く用意 */

    //配列の読み込み
    for (i = 0; i < NUMBER; i++)
    {
        printf("vx[%d]", i);
        scanf("%d", &vx[i]);
    }

    //探索キーの指定
    printf("search number >> ");
    scanf("%d", &ky);

    //結果を表示する
    if ((idx = search(vx, ky, NUMBER)) == FAILED)
    {
        puts("\afailed...");
    }
    else
    {
        printf("success!! %d is vx[%d]\n", ky, idx);
    }
    return 0;
}

/* 要素数ｎの配列ｖから、key と一致する要素を探索（番兵法） */
int search(int v[], int key, int n)
{
    int i = 0;
    v[n] = key; /* 番兵を格納 */

    while (1)
    {
        if (v[i] == key)
        {
            break;
        }
        i++;
    }
    return (i < n) ? i : FAILED;
}

/*
******番兵法******
配列の最後に探索する値を追加
・探索キーがなくても、最後の番兵で必ず停止する

 */