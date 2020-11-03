//***************************************************
/** 大文字・小文字の変換
 * toupper()：小文字→大文字への変換
*/
//***************************************************

#include <stdio.h>
#include <ctype.h>

void str_toupper(char[]);
void str_tolower(char[]);

int main(void)
{
    char str[256];
    puts("文字列を入力して下さい");
    scanf("%s", str);

    str_toupper(str);

    printf("大文字 >>");
    printf("%s\n", str);

    str_tolower(str);
    printf("小文字 >>");
    printf("%s\n", str);

    return 0;
}

void str_toupper(char str[])
{
    int i = 0;

    while (str[i])
    {
        str[i] = toupper(str[i]);
        i++;
    }
}

void str_tolower(char str[])
{
    int i = 0;

    while (str[i])
    {
        str[i] = tolower(str[i]);
        i++;
    }
}