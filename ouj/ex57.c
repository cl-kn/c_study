#include <stdio.h>

int is_prime(int);

int main(void)
{
    int number;

    printf("３以上の整数を入力してください ＞");
    scanf("%d", &number);

    if (is_prime(number) == 1)
    {
        printf("%d は素数です。", number);
    }
    else
    {
        printf("%d は素数ではありません。", number);
    }

    return 0;
}

int is_prime(int prime)
{
    if (prime % 2 == 0 || prime % 3 == 0)
    {
        return 0;
    }

    for (int x = 4; prime > x; x++)
    {
        if (prime % x == 0)
        {
            return 0;
        }
    }
    return 1;
}
