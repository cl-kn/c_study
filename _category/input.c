//***************************************************
/** 入力デバッグ */
//***************************************************

#include <stdio.h>

int main(void)
{
    char *str[256];
    printf(">> ");
    scanf("%s", str);

    printf("\n>> %s",str);

    return 0;
}