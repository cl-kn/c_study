//***************************************************
/** 文字列の比較 */
//***************************************************

#include <stdio.h>
#include <string.h>

int main(void)
{
    int i, len;

    char str1[256], str2[] = "DOG";

    scanf("%s", str1);
    len = strlen(str2);

    for (i = 0; i < len + 1; i++)
    {
        if (str1[i] != str2[i])
        {
            break;
        }
    }

    // 異なる文字がない＝変数iの値が最後までインクリされている
    if (i == len + 1) //文字列の比較は、EOSまで等しい必要があるため、＋１している
    {
        printf("同じ\n");
    }
    else
    {
        printf("違う\n");
    }

    return 0;
}