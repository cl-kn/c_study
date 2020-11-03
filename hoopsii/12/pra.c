#include <stdio.h>
#include <string.h>

//***************************************************
/**
 * 第12回演習問題Ⅲ
 * 練習
 */
//***************************************************

int main(void)
{
    char str[256][256];
    int i = 0;

    printf("文字列を入力\n");

    while (1)
    {
        scanf("%s", str[i]);
        // printf("%s", str[i]);

        if (strcmp(str[i], "END") == 0)
        {
            i--;
            break;
        }
        i++;
    }

    // i の値は、配列インデックスの最後の値
    for (i; i >= 0 ;i--)
    {
        printf("%s\n", str[i]);
    }

    return 0;
}