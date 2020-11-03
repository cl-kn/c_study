//***************************************************
/** 6-13：線形探索（逐次探索） */
//***************************************************

#include <stdio.h>
#define NUMBER 5  /* 要素数 */
#define FAILED -1 /* 探索失敗 */

int search(const int[], int, int);

int main(void)
{
    int i, ky, idx; //i=配列用、ky = 探索するキー、idx = 結果の表示用
    int vx[NUMBER];

    //配列の読み込み
    for (i = 0; i < NUMBER; i++)
    {
        printf("vx[%d]", i);
        scanf("%d", &vx[i]);
    }

    //探索キーの指定
    printf("search number >> ");
    scanf("%d", &ky);

    idx = search(vx, ky, NUMBER);

    //結果を表示する
    if (idx == FAILED)
    {
        puts("\afailed...");
    }
    else
    {
        printf("success!! %d is vx[%d]\n", ky, idx);
    }

    return 0;
}

/* 要素数ｎの配列ｖからkeyと一致する要素を探索 */

int search(const int v[], int key, int n)
{
    int i = 0;

    while (1)
    {
        // キーが見つからず、配列の最後の値 v[要素数 - 1] まで探索を終えた
        if (i == n)
        {
            return FAILED;
        }
        //キーが見つかったら、その添え字を返す
        if (v[i] == key)
        {
            return i;
        }
        i++;
    }
}

/*
******線形探索******
配列の先頭から値を検査し、要素を発見したら探索を終了する。
「停止の条件」
・配列の最後まで探す
・探したい値が見つかる

 */