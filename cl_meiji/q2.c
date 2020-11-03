//***************************************************
/**第2回 文字
 * 課題3
 * 文字数カウント
 * 文字リバース表示
*/
//***************************************************

#include <stdio.h>

int main(void)
{
    int i = 0, count = 0;
    char str[6];

    printf("input string >> ");
    scanf("%s", str);

    // printf("%s", str);

    while (str[i] != '\n')
    {
        i++;
    }
    // a i u e o \n str[6]
    count = i;

    for (i = count - 1; i >= 0; i--)
    {
        printf("%c", str[i]);
    }

    return 0;
}