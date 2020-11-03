//***************************************************
/**  */
//***************************************************

#include <stdio.h>

void funcA();
void funcB();

int main(void)
{
    funcA();

    return 0;
}

void funcA()
{

    int a1 = 5;

    funcB();

    printf("funcA : a1 = %d\n", a1);
}

void funcB()
{

    int b1 = 100;
    int b2 = 200;

    printf("funcB : b1 = %d, b2 = %d\n", b1, b2);
}