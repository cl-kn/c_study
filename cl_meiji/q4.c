//***************************************************
/** 第4回：関数(1) */
//***************************************************

#include <stdio.h>

int square(int);
int square2();

int main(void)
{
    int value = square2();

    printf("%d", value);

    return 0;
}

//(1) 2乗を返す関数
int square(int x)
{
    return x * x;
}

//(3) １～１０の数の2乗の和を求める関数

int square2()
{
    int i, sum = 0;

    for (i = 1; i <= 10; i++)
    {
        sum += square(i);
        // printf("sum = %d\n",sum);
    }

    return sum;
}