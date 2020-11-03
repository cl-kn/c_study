//***************************************************
/** 9-2 配列に文字列を格納 */
//***************************************************

#include <stdio.h>

int main(void)
{
    int i;
    char str[4];

    str[0] = 'D';
    str[1] = 'O';
    str[2] = 'G';
    str[3] = '\0';

    printf("文字列\"str\" = %s\n", str);

    for (i = 0; i < 4; i++)
    {
        printf("str[%d] = %d\n", i, str[i]);
    }

    return 0;
}