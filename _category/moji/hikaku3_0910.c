//***************************************************
/** 文字の比較（1文字） */
//***************************************************

#include <stdio.h>
#include <string.h>

int main(void)
{
    char s[] = "112234";

    // [r]が、配列sの要素と一致するか
    // printf("%s", s);
    // printf("[r] 文字コード%d\n", 'r');
    // printf("s[2](r) 文字コード%d\n", 'r');

    // if ('r' == s[2])
    // {
    //     printf("rはs[2]と一致！");
    // }
    // else
    // {
    //     printf("rはs[2]と不一致");
    // }

    int count = 0, len = strlen(s);

    for (int i = 0; i < len; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (s[i] == s[j])
            {
                count++;
            }
        }
    }

    printf("同じ数値の数：%d", count);

    return 0;
}