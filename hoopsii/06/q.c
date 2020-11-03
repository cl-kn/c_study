#include <stdio.h>

//***************************************************
/** 第6回
 * 簡易計算機
 */
//***************************************************
int sum;
int add(int, int);
int sub(int, int);
int mul(int, int);
int div(int, int);

int main(void)
{
    int i, num, x, y;

    while (1)
    {
        printf("簡易計算機\n");
        printf("加算=>1、減算=>2、乗算=>3、除算=>4、終了=>0\n");

        printf("どの計算をしますか？ ==>");
        scanf("%d", &num);

        if (num == 0 || 4 < num)
        {
            printf("終了します");
            break;
        }

        printf("x >>");
        scanf("%d", &x);
        printf("y >>");
        scanf("%d", &y);

        switch (num)
        {
        case 1:
            printf("%d + %d = %d\n", x, y, add(x, y));

            break;
        case 2:
            printf("%d - %d = %d\n", x, y, sub(x, y));

            break;
        case 3:
            printf("%d * %d = %d\n", x, y, mul(x, y));

            break;
        case 4:
            printf("%d / %d = %d\n", x, y, div(x, y));
            break;
        default:
            break;
        }
    }
    return 0;
}

int add(int x, int y)
{
    sum = x + y;
    return sum;
}

int sub(int x, int y)
{
    sum = x - y;
}

int mul(int x, int y)
{
    sum = x * y;
}

int div(int x, int y)
{
    sum = x / y;
}