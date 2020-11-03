//***************************************************
/** 文字列内の文字を2進数と16進数で表示する */
//***************************************************

#include <stdio.h>
#include <ctype.h>
#include <limits.h>

void strdump(const char *s)
{
    while (*s)
    {
        int i;
        unsigned char x = (unsigned char)*s;

        printf("%c  ", isprint(x) ? x : ' '); //文字
        printf("%0*X", (CHAR_BIT + 3) / 4, x);

        for (i = CHAR_BIT - 1; i >= 0; i--)
        {
            putchar(((x >> i) & 1U) ? '1' : '0');
            putchar('\n');
            s++; // ポインタを進める
        }
    }
}

int main(void)
{

    puts("漢字");
    strdump("漢字");
    putchar('\n');

    puts("12日本語AB");
    strdump("12日本語AB");
    putchar('\n');

    return 0;
}

/*
「CHAR_BIT」
ヘッダ：#include <limits.h>
書式：#define CHAR_BIT 8
機能：バイトのビット数を表す
戻り値：
*/