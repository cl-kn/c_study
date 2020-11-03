//***************************************************
/** 配列に文字列を格納 */
//***************************************************

#include <stdio.h>

int main(void)
{
    char str1[] = "BIG DOG";
    char str2[] = {'A', 'B', 'C', '\0'};

    printf("str1 = %s\n", str1);
    printf("str2 = %s\n", str2);

    return 0;
}