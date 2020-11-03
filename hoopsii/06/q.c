#include <stdio.h>

//***************************************************
/** ‘æ6‰ñ
 * ŠÈˆÕŒvZ‹@
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
        printf("ŠÈˆÕŒvZ‹@\n");
        printf("‰ÁZ=>1AŒ¸Z=>2AæZ=>3AœZ=>4AI—¹=>0\n");

        printf("‚Ç‚ÌŒvZ‚ğ‚µ‚Ü‚·‚©H ==>");
        scanf("%d", &num);

        if (num == 0 || 4 < num)
        {
            printf("I—¹‚µ‚Ü‚·");
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