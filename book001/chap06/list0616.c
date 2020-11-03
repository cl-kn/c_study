//***************************************************
/** 多次元配列の受け渡し
 * 4名の3科目のテスト点数、2回分の合計を表示する
*/
//***************************************************

#include <stdio.h>

void add_arr(const int arr1[4][3], const int arr2[4][3], int sum[4][3]);
void print_arr(const int arr[4][3]);

int main(void)
{
    int score1[4][3] = {{91, 63, 78}, {67, 72, 46}, {89, 34, 53}, {32, 54, 34}};
    int score2[4][3] = {{97, 67, 82}, {74, 43, 46}, {97, 56, 21}, {85, 46, 35}};
    int sum[4][3] = {};

    add_arr(score1, score2, sum);
    printf("[score...No1]\n");
    print_arr(score1);
    printf("[score...No2]\n");
    print_arr(score2);
    printf("[score...sum]\n");
    print_arr(sum);
}

void add_arr(const int arr1[4][3], const int arr2[4][3], int sum[4][3])
{
    int i, j;
    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 3; j++)
        {
            sum[i][j] = arr1[i][j] + arr2[i][j];
        }
    }
}

void print_arr(const int arr[4][3])
{
    int i, j;
    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 3; j++)
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
    printf("**********************************\n");
}
