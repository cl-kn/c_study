//***************************************************
/** 演習９－９
 * 入力文字列を反転して返す ※strlen()を利用
 * void rev_string(char str[]) {}
 */
//***************************************************

#include <stdio.h>
#include <string.h>

void rev_string(char str[]);

int main(void)
{
    char str[256];

    puts("******文字列を入力して下さい******");
    scanf("%s", str);

    puts("******文字列を反転しました******");
    rev_string(str);
    puts(str);

    return 0;
}

void rev_string(char str[])
{
    int i;
    int len = strlen(str);

    for (i = 0; i < len / 2; i++)
    {
        char temp = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = temp;
    }
}