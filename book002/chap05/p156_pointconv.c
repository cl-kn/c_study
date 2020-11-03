//***************************************************
/** 明示的キャストについて */
//***************************************************

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    double x;
    double *pd;
    double *pc = &x;

    // pd++;
    pd = pc;
    pd++;
    pd++;

    printf("pc = %p\n", pc);
    printf("pd = %p\n", pd);

    return 0;
}