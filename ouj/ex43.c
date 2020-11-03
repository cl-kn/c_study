#include <stdio.h>
int main(void)
{

    int i = 100;

    // for (i; i > 0; i--)
    // {
    //     if (i % 3 == 0 || i % 5 == 0)
    //     {
    //         printf("%d ", i);
    //     }
    // }

    // printf("\n");

    int count = 100;

    while (count > 0)
    {
        if (count % 3 == 0 || count % 5 == 0)
        {
            printf("%d ", count);
        }

        count--;
    }

    return 0;
}

// １～１００のうち、３か５の倍数を降順に表示するPG