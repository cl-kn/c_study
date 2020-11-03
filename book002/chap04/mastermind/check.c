//***************************************************
/**  */
//***************************************************

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
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
        //error code 2：数字以外の文字が含まれる
        if (!isdigit(s[i]))
        {
            return 2;
        }

        for (j = 0; j < i; j++)
        {
            //error code 3：同一文字が含まれる
            if (s[i] == s[j])
            {
                return 3;
            }
        }
    }
    // return 0;
}

int main(void)
{
    char str[] = "1234";

    printf("%d", check(str));

    return 0;
}