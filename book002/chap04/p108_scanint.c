//***************************************************
/** int型の数値の読み取り */
//***************************************************

#include <stdio.h>

int main(void)
{
    int x;
    scanf("%d", &x);
    printf("input number = %d", x);

    return 0;
}

//数値読み取りの際、先頭の０は無視される