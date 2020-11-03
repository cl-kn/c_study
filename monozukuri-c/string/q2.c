//***************************************************
/**  課題２ NULL文字
 * https://monozukuri-c.com/langc-string-beginner
 * 10月29日
*/
//***************************************************

#include <stdio.h>

int main(void)
{
    char str[] = "Hello World";

    str[5] = '\0';

    printf("%s",str);

    return 0;
}