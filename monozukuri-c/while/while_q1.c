//***************************************************
/** while文 課題
 * https://monozukuri-c.com/langc-while/
 * 10月29日
 */
//***************************************************

#include <stdio.h>

void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
};

void calc_lcm(int num1, int num2)
{
    int count = 1;

    while (1)
    {
        if (count % num1 != 0)
        {
            count++;
            continue;
        }
        if (count % num2 != 0)
        {
            count++;
            continue;
        }
        printf("最小公倍数 %d, %d ==> %d\n", num1, num2, count);
        break;
    }
}

int main(void)
{
    int number1 = 11;
    int number2 = 34;

    int r, temp;
    int x = number1 * number2;

    if (number1 < number2)
    {
        swap(&number1, &number2);
    }

    r = number1 % number2;

    while (r != 0)
    {
        number1 = number2;
        number2 = r;
        r = number1 % number2;
    }

    printf("最大公約数 %d\n", number2);
    printf("最小公倍数 %d\n", x / number2);

    calc_lcm(11, 34);

    return 0;
}