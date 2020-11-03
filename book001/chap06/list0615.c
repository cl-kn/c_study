//***************************************************
/** 6-15：逐次探索：番兵法（for文ver） */
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

    //探索キーの指定 （番兵用にも使う）
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
    /* 番兵を格納 */
    /* 配列の最後尾に番兵を格納 */
    v[n] = key;

    // while を for文で書き換え
    for (i; v[i] != key; i++)
    {
    };
    return (i < n) ? i : FAILED;
}