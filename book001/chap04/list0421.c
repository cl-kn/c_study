#include <stdio.h>
int main(void)
{

    // 九九表示
    int i, j;

    for (i = 1; i <= 9; i++)
    {
        for (j = 1; j <= 9; j++)
        {
            printf("%3d", i * j);
        }
        putchar('\n');
    }

    return 0;
}