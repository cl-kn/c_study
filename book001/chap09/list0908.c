//***************************************************
/** 文字列の長さ */
//***************************************************

#include <stdio.h>

// 文字列数を返す関数
int str_len(const char s[])
{

    int len = 0;

    // s[len]  != '\0' と同じ意
    // 以下の while文を評価すると、s[len] はtrue(1)であるが、s[len] = 0 つまり、終端を指すNULL文字に到達すると 0 となるのでループを抜ける
    while (s[len])
    {
        len++;
    }
    return len;
}

int main(void)
{
    char str[128];

    printf("文字列を入力 >>");
    scanf("%s", str);

    printf("文字列数：%d", str_len(str));

    return 0;
}

/*
str[128] = {'aiueo'} の場合、

str_len(str) を実行すると、
s[0] の時、 len++ = 1
s[1] の時、 len++ = 2
s[2] の時、 len++ = 3
s[3] の時、 len++ = 4
s[4] の時、 len++ = 5

で、文字列数は５
 */