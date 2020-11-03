//***************************************************
/** 演習：6-11
 * 要素数nの配列v内のkeyと等しい全要素の添え字を配列idxに格納する関数search_idxの作成
 * 戻り値：keyと等しい要素の個数
 * int search_idx(const int v[], int idx[], int key, int n){}
 * 例：array[5] = {1,3,5,3,91} で key = 3 ならば、
 * idx に {1,3} を格納したうえで、idxの要素数 3 を返却する
*/
//***************************************************

#include <stdio.h>
#define NUMBER 5
// #define TRUE 1
// #define FALSE 0

// int search_idx(const int[], int *, int, int);
int search_idx2(const int[], int *, int, int);

int main(void)
{
    int i, ky, count;
    int vx[NUMBER];
    int idx[10];
    int *p_idx = idx;

    //配列の読み込み
    for (i = 0; i < NUMBER; i++)
    {
        printf("vx[%d]", i);
        scanf("%d", &vx[i]);
    }

    //探索キーの指定
    printf("search number >> ");
    scanf("%d", &ky);

    count = search_idx2(vx, p_idx, ky, NUMBER);

    printf("count = %d\n", count);
    printf("p_idx[] = ");
    for (i = 0; i < count; i++)
    {
        printf("%d ", p_idx[i]);
    }

    return 0;
}

/*
v[]     探索する配列
idx[]   結果を格納する配列
key     探索キー
n       配列の要素数
*/

int search_idx2(const int v[], int *idx, int key, int n)
{
    int count = 0, i = 0, j = 0;

    for (i; i < n; i++)
    {
        if (v[i] == key)
        {
            count += 1;
            idx[j] = i;
            j++;
        }
    };
    // return (i < n) ? i : FAILED;
    return count;
}