//***************************************************
/** 課題１
 * https://monozukuri-c.com/langc-if/#toc19
 */
//***************************************************

#include <stdio.h>

int main(void)
{
    int number = 71;

    if (number % 2 == 0)
    {
        printf("prime : %d\n", number);
    }
    else
    {
        printf("not prime : %d\n", number);
    }

    return 0;
}