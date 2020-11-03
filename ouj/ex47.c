#include <stdio.h>
int main(void)
{
    char initial = 'o';

    for (int i = 1; i <= 10; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            printf("%c", initial);
        }
        printf("\n");
    }

    return 0;
}
