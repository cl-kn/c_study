//***************************************************
/** 第６回：関数まとめ
 * (2) 入力値10個を配列に格納して表示する
*/
//***************************************************

#include <stdio.h>
#define NUM 3

void input(float *, int);
void output(float *, int);

int main(void)
{
    float input_f[NUM];
    input(input_f, NUM);
    output(input_f, NUM);

    return 0;
}

//（２）配列の入力と表示
//キーボード入力
void input(float *p_arr, int arr_num)
{
    int i;
    printf("please enter a number\n");
    for (i = 0; i < arr_num; i++)
    {
        printf("input_f[%d] >> ", i);
        scanf("%f", &p_arr[i]);
    }
}

//配列の表示
void output(float *p_arr, int arr_num)
{
    int i;
    printf("\n----print input_f----\n\n");
    for (i = 0; i < arr_num; i++)
    {
        printf("input_f[%d] = %.1f\n", i, p_arr[i]);
    }
}