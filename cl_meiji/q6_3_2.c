//***************************************************
/** 第６回：関数まとめ
 * (3) 実数入力値10個を配列に格納し、平均値算出、降順ソートを行う

score[5][2] = {

    {90,0},
    {100,1}.
    {55,2},
    {87,3},
    {92,4}

}

*/
//***************************************************

#include <stdio.h>
#define NUM 5

void input(float *, int);
void output_arr(float *, int);
float calc_ave(float *, int);
float calc_sum(float *, int);
void sort_de(float *, int);
void swap(float *, float *);
void copy_arr(float *, float *, int);
void insert_zero(float *, int);
void copy_arr_index(float *, float *, int);

float arr_copy[NUM][1];
float arr_copy_index[NUM][1];

int main(void)
{
    float input_f[NUM][2];
    input(input_f, NUM);
    insert_zero(arr_copy, NUM);
    insert_zero(arr_copy_index, NUM);
    copy_arr(input_f, arr_copy, NUM);

    puts("----------------");

    printf("score:sum = %.0f\n", calc_sum(input_f, NUM));
    printf("score:average = %.2f\n", calc_ave(input_f, NUM));

    sort_de(input_f, NUM);
    output_arr(arr_copy, NUM);

    return 0;
}

//実数値を入力で受け取る
void input(float *p_arr, int arr_num)
{
    int i;
    printf("please enter a number\n");
    for (i = 0; i < arr_num; i++)
    {
        printf("No.%d >> ", i + 1);
        scanf("%f", &p_arr[i]);
    }
}

// 配列の表示
void output_arr(float *p_arr, int arr_num)
{
    int i;
    printf("\n----print input_f----\n\n");
    for (i = 0; i < arr_num; i++)
    {
        printf("No.%d = %.0f\n", i + 1, p_arr[i]);
    }
}

//配列の合計値を算出
float calc_sum(float *p_arr, int arr_num)
{
    int i;
    float sum = 0;

    for (i = 0; i < arr_num; i++)
    {
        sum += p_arr[i];
    }

    return sum;
}

// 配列の平均値を算出
float calc_ave(float *p_arr, int arr_num)
{
    float ave = 0;
    ave = calc_sum(p_arr, NUM) / arr_num;

    return ave;
}

//配列を降順にソート
void sort_de(float *p_arr, int arr_num)
{
    int i, j;

    for (i = 0; i < arr_num; i++)
    {
        for (j = i + 1; j < arr_num; j++)
        {
            if (p_arr[i] < p_arr[j])
            {
                // swap(p_arr[i], p_arr[j]);

                float tmp = 0;
                tmp = p_arr[i];
                p_arr[i] = p_arr[j];
                p_arr[j] = tmp;
            }
        }
    }

    puts("---- sort by descending order ----");

    for (i = 0; i < arr_num; i++)
    {
        printf("[%.0f]\n", p_arr[i]);
    }
}

//値の入れ替え
void swap(float *p1, float *p2)
{
    float tmp = 0;

    tmp = *p1;
    *p1 = *p2;
    *p2 = tmp;
}

//配列のコピー
void copy_arr(float *p_arr1, float *p_arr2, int arr_num)
{
    int i;

    for (i = 0; i < arr_num; i++)
    {
        p_arr2[i] = p_arr1[i];
    }
}

//配列のインデックス値をコピー
void copy_arr_index(float *p_arr1, float *p_arr2, int arr_num)
{
    int i;
    for (i = 0; i < arr_num; i++)
    {
    }
}

//配列に0を挿入
void insert_zero(float *p_arr, int arr_num)
{
    int i;
    for (i = 0; i < arr_num; i++)
    {
        p_arr[i] = 0;
    }
}