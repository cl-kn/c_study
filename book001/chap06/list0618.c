//***************************************************
/** 自動記憶領域期間と静的記憶領域期間(static) */
//***************************************************

#include <stdio.h>
int func(void);

int fx = 0;

int main(void)
{
    int i;
    puts("ax sx fx");
    puts("----------------------");

    for (i = 0; i < 10; i++)
    {
        func();
        puts("");
    }
    puts("----------------------");

    return 0;
}

int func(void)
{
    static int sx = 0; /* 静的記憶領域期間＋スコープ有効範囲 */
    int ax = 0;        /* 自動記憶領域期間＋スコープ有効範囲 */

    printf("%3d%3d%3d", ax++, sx++, fx++);
}