//***************************************************
/** 11-5：文字列の長さを調べる（ポインタによる走査） */
//***************************************************

#include <stdio.h>
int str_length(const char *);

int main(void)
{
    char str[256];
    printf("文字列を入力して下さい。");
    scanf("%s", str);

    printf("文字列の長さ：%d", str_length(str));

    return 0;
}

int str_length(const char *str)
{

    int len = 0;

    //終端文字に至ると０を返す→whileループ脱出
    while (*str++)
    {
        len++;
    }
    return len;
}