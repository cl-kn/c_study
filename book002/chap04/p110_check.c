//***************************************************
/** 入力値文字列sの妥当性をチェック */
//***************************************************

#include <stdio.h>
#include <string.h>
#include <ctype.h>

int check(const char s[])
{
    int i, j;

    //error code 1：文字列が４文字ではない
    if (strlen(s) != 4)
    {
        return 1;
    }

    for (i = 0; i < 4; i++)
    {
        //error code 2：数字以外の文字が含有
        if (!isdigit(s[i]))
        {
            return 2;
        }
        for (j = 0; j < i; j++)
        {
            //error code 3：同一文字の含有
            if (s[i] == s[j])
            {
                return 3;
            }
        }
    }
}

int main(void)
{
    char s[] = "1234";

    switch (check(s))
    {
    case 1:
        printf("error code1\n文字列が4文字ではない");
        break;
    case 2:
        printf("error code2\n数字以外の文字が含まれている");
        break;
    case 3:
        printf("error code3\n同じ数値文字が含まれている");
        break;

    default:
        break;
    }

    return 0;
}