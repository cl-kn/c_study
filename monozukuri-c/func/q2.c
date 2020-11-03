//***************************************************
/**課題２
 * サイト：https://monozukuri-c.com/langc-function/
 * 10月29日
 */
//***************************************************

#include <stdio.h>

//階乗を算出
unsigned long getFactorial(unsigned short number)
{
    unsigned long factorial = 1; //階乗の値
    int i;

    for (i = 1; i <= number; i++)
        {
            // factorial = factorial * i;
            factorial *= i;
        }
        return factorial;

    return factorial;
}

int main(void)
{
    unsigned long num = 0;
    printf("%dの階乗 => %d\n", num, getFactorial(num));

    return 0;
}