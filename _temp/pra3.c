#include <stdio.h>
#include <string.h>

//***************************************************
/**
 * お試し用
 */
//***************************************************

int main(void)
{
    int length, i = 0;

    // array1 入力値保存用
    // array2 初期設定文字
    char array1[256], array2[] = "DOG";

    printf("半角英数字を入力してください >> ");
    scanf("%s", array1);
    length = strlen(array2);

    for (i = 0; i < length; i++)
    {
        if (array1[i] != array2[i])
            break;
    }

    if (i == length + 1)
    {
        printf("ok\n");
    }
    else
    {
        printf("no\n");
    }

    return 0;
}