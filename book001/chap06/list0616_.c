//***************************************************
/** 多次元配列の受け渡し
 * 4名の3科目のテスト点数、2回分の合計を表示する
 * 1回目
 * 91 59 80
 * 48 67 74
 * 99 89 95
 * 20 100 100
 * 2回目
 * 55 49 89
 * 66 79 85
 * 99 95 93
 * 95 100 100
 * 合計点
 *
*/
//***************************************************

#include <stdio.h>
#define NUMARR1 4
#define NUMARR2 3

void add_arr(int[][], int[][], int[][]);
void print_arr();

int main(void)
{
    int sum[NUMARR1][NUMARR2];
    return 0;
}

void add_arr(int arr1[][], int arr2[][], int sum[][])
{
    int i, j;
    for (i = 0; i < NUMARR1; i++)
    {
        for (j = 0, j < 3; j++)
        {
            sum[i][j] = arr1[i][j] + arr2[i][j];
        }
    }
}

void print_arr(int arr[][])
{
    int i, j;
    for (i = 0; i < NUMARR1; i++)
    {
        for (j = 0; j < 3; j++) {

        }
    }
}
