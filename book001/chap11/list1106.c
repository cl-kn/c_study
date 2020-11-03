//***************************************************
/** 11-6：文字列のコピー
 */
//***************************************************

#include <stdio.h>

char *str_copy(char *d, const char *s)
{
    char *t = d;

    while (*d++ = *s++)
    {
        ;
    }

    //戻り値：コピー先の文字列の先頭文字へのポインタ
    return t;
}

int main(void)
{
    char str[256] = "Before";
    char temp[256];

    printf("str = \"%s\"\n", str);
    printf("コピーする文字列を入力\n>>");
    scanf("%s", temp);
    printf("コピー完了\n");

    //str_copy()の戻り値がポインタの為
    printf("str = \"%s\"\n", str_copy(str, temp));

    return 0;
}
