//***************************************************
/** クイックソート
 * ライブラリの利用
 * qsort()
 */
//***************************************************

#include <stdio.h>
#include <stdlib.h>

int compare_int(const void *x, const void *y)
{
    return *(int *)x - *(int *)y;
}

void printData(int *arr, int arrNum)
{
    int i;

    for (i = 0; i < arrNum; i++)
    {
        printf("%d, ", arr[i]);
    }
    putchar('\n');
}

int main(void)
{
    int arr[] = {5, 3, 9, 2, 4, 7, 6, 8, 0, 44};
    int i;

    printf("\n-----before-----\n\n");
    printData(arr, 10);

    qsort(arr, 10, sizeof(int), compare_int);

    printf("\n-----after-----\n\n");
    printData(arr, 10);
    return 0;
}

/***
 * [～～qsort関数～～]
 *
 * [include] stdlib.h
 * [関数仕様] void qsort(void *base, size_t num, size_t size, int (* cmpFunc)(const void * n1, const void *n2));
 * [第1引数] base:対象配列データへの先頭アドレス
 * [第2引数] num:対象配列の要素数
 * [第3引数] size:対象のデータ1つ分のバイト数
 * [第4引数] cmpFunc:並べ替えをするための大小比較用関数へのポインタ
 * 戻り値 なし
 *
 * [第4引数] 比較用関数を定義する必要がある******************************
 *
 * int 比較用関数名(const void * n1, const void *n2);
 * [第1引数] n1 入れ替え対象となる1つ分のデータへのポインタ
 * [第2引数] n2 入れ替え対象となる1つ分のデータへのポインタ
 * [戻り値]
 * 「0」「1」「-1」の3種類を比較結果として返却
 * ・昇順：n1 > n2 のときに1を返却、n1 < n2 のときに -1 を返却
 * ・降順：n1 < n2 のときに1を返却、n1 > n2 のときに -1 を返却
 * ・同一値の場合、「０」を返却
 * /