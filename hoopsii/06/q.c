#include <stdio.h>

//***************************************************
/** ��6��
 * �ȈՌv�Z�@
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
        printf("�ȈՌv�Z�@\n");
        printf("���Z=>1�A���Z=>2�A��Z=>3�A���Z=>4�A�I��=>0\n");

        printf("�ǂ̌v�Z�����܂����H ==>");
        scanf("%d", &num);

        if (num == 0 || 4 < num)
        {
            printf("�I�����܂�");
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