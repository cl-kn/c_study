#include <stdio.h>

//***************************************************
/**
 * ポインタと関数
 */
//***************************************************

void height_up(int *height)
{
    if (*height < 180)
    {
        *height = 180;
    }
}

int main(void)
{
    int shiro = 179;
    int pochi = 160;
    int tama = 189;

    height_up(&shiro);

    printf("%d\n", shiro);
    printf("%d\n", pochi);
    printf("%d\n", tama);

    return 0;
}