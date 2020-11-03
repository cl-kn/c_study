#include <stdio.h>

/**********************************
九九表示プログラム
**********************************/

int main(void)
{
    printf("九九表\n");

    for (int i = 0; i < 10; i++)
    {
        printf("%d  ", i);
        if (i == 9)
        {
            printf("\n");
        }
    }

    printf("-----------------------------\n");

    for (int i = 1; i < 10; i++)
    {
        printf("%d| ", i);
        for (int j = 1; j < 10; j++)
        {
            if (j * i >= 10)
            {
                printf("%d ", j * i);
            }
            else
            {
                printf(" %d ", j * i);
            }
        }
        printf("\n");
    }

    return 0;
}