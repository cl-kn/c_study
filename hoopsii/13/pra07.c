#include <stdio.h>

//***************************************************
/**
 * 第13回 ポインタ
 * 例題7 関数に渡す引数にポインタを使った例
 */
//***************************************************

void calc(int *p_point, int *p_sum, int *p_avg);

int main(void)
{
    int point[5], sum = 0, avg = 0, i;

    for (i = 0; i < 5; i++)
    {
        printf("no%d -> ", i + 1);
        scanf("%d", &point[i]);
    }

    calc(point, &sum, &avg); //それぞれのアドレスをcalc関数に渡す
    printf("sum: %d average:%d\n", sum, avg);

    return 0;
}

void calc(int *p_point, int *p_sum, int *p_avg)
{
    for (int i = 0; i < 5; i++)
    {
        //ポインタp_sumが指すアドレスの中身に、
        //ポインタp_sumが指すアドレスの中身と、
        //ポインタp_pointが指すアドレス+iの中身を代入
        *p_sum = *p_sum + *(p_point + i);

        // *p_pointには先頭アドレスが格納されているので、すべての値を使用したいときは、アドレスを +１していけば、順番に値が利用できる。
    }

    //ポインタp_avgが指すアドレスの中身に
    //ポインタp_sumが指すアドレスの中身を5で割ったものを代入
    *p_avg = *p_sum / 5;
}