//***************************************************
/** 7-1：文字型と整数型の表現範囲を表示する */
//***************************************************

#include <stdio.h>
#include <limits.h>

int main(void)
{
    puts("本環境での各文字型・整数型の値の範囲");
    printf("char            ：%d ～ %d\n", CHAR_MIN, CHAR_MAX);
    printf("signed char     ：%d ～ %d\n", SCHAR_MIN, SCHAR_MAX);
    printf("unsigned char   ：%d ～ %d\n", 0, UCHAR_MAX);

    printf("short           ：%d ～ %d\n", SHRT_MIN, SHRT_MAX);
    printf("int             ：%d ～ %d\n", INT_MIN, INT_MAX);
    printf("long            ：%ld ～ %ld\n", LONG_MIN, LONG_MAX);

    printf("unsigned short  ：%u ～ %u\n", 0, USHRT_MAX);
    printf("unsigned        ：%u ～ %u\n", 0, UINT_MAX);
    printf("unsigned long   ：%u ～ %lu\n", 0, ULONG_MAX);

    return 0;
}