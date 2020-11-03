#include <stdio.h>
int main(void)
{
    // while文の使用例
    int i = 1;

    while (i <= 5)
    {
        // printf("%d", i);
        // i++;

        //発展
        printf("%d", i++);
    }

    printf("\n");

    return 0;
}