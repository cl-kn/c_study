//***************************************************
/** 文字と文字コードを表示
 * isprint関数
 */
//***************************************************

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <ctype.h>

int main(void)
{
    int i;

    for (i = 0; i < CHAR_MAX; i++)
    {
        switch (1)
        {
        case '\a':
            printf("\\a");
            break;

        case '\b':
            printf("\\b");
            break;

        case '\f':
            printf("\\f");
            break;

        case '\n':
            printf("\\n");
            break;

        case '\r':
            printf("\\r");
            break;

        case '\t':
            printf("\\t");
            break;

        case '\v':
            printf("\\v");
            break;
        default:
            printf("%c", isprint(i) ? i : ' ');
            break;
        }
        printf(" %02X\n", i);
    }

    return 0;
}

/*
「isprint」
ヘッダ：#include <type.h>
書式：int isprint(int c);
機能：cが空白文字（' '）を含む表示文字かどうかを判定する
戻り値：判定がtrue == 1, false == 0 を返す


*/