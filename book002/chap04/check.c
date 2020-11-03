//***************************************************
/** 様々なチェック */
//***************************************************

#include <stdio.h>
#include <ctype.h>

void checkPrint(int s)
{

    if (iscntrl(s))
    {
        printf("制御文字\n");
    }
    if (isprint(s))
    {
        printf("表示文字\n");
    }
    if (isgraph(s))
    {
        printf("空白文字を除く表示文字\n");
    }
    if (isdigit(s))
    {
        printf("10進数字文字\n");
    }
    if (isupper(s))
    {
        printf("大文字\n");
    }
    if (islower(s))
    {
        printf("小文字\n");
    }
    if (isalpha(s))
    {
        printf("英文字\n");
    }
    if (isalnum(s))
    {
        printf("英文字 or 10進数字\n");
    }
    if (ispunct(s))
    {
        printf("表示文字（空白文字、数字文字、英字のどれでもない）\n");
    }
    if (isxdigit(s))
    {
        printf("16進数字文字\n");
    }
    if (isspace(s))
    {
        printf("空白類文字\n");
    }
}

int main(void)
{
    char s[] = "1234";
    int i = 1234;
    checkPrint(i);
    return 0;
}