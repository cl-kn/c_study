//***************************************************
/** 再帰的関数 */
//***************************************************

#include <stdio.h>
#define NUM 10;

int factorial(int n)
{
    if (n > 0)
    {
        return n * factorial(n - 1);
    }
    else
    {
        return 1;
    }
}

int main(void)
{
    int i;

    for (i = 0; i < 10; i++) {
        printf("%d! = %d\n",i,factorial( i));
    }

}