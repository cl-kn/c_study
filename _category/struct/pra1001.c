//***************************************************
/** 10/1 構造体メモ */
//***************************************************

#include <stdio.h>

int main(void)
{
    typedef struct
    {
        int x;
        int y;
    } Add;

    Add a1;

    a1.x = 55;

    printf("%d",a1.x);

    return 0;
}