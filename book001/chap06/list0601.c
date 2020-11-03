#include <stdio.h>
#define max22(a,b)


//***************************************************
/**
 * 二つの整数の大きい方の値を求める関数
 */
//***************************************************

int max2(int, int);

int main(void)
{
    int a = 2;
    int b = 5;
    printf("%d と %d で大きい値は、 %d ", a, b, max2(a, b));

    return 0;
}

int max2(int num1, int num2)
{
    if (num1 > num2)
    {
        return num1;
    }
    else
    {
        return num2;
    }
}
