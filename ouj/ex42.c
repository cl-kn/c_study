#include <stdio.h>
int main(void)
{
    int i = 0;

while (1)
    {
        ++i;

        // １００より大きいとwhile文終了
        if (i > 100)
        {
            break;
        }

        // 3 or 5の倍数はスルー
        if (i % 3 == 0 || i % 5 == 0)
        {
            continue;
        }

        printf("%d ", i);
    }

    printf("\n");

    return 0;
}