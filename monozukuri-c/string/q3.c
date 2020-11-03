//***************************************************
/**  課題３ 文字列の長さ
 * https://monozukuri-c.com/langc-string-beginner
 * 10月30日
*/
//***************************************************

#include <stdio.h>
#include <string.h>

int main(void)
{
    char str[] = "Hello World";
    int len = strlen(str);

    printf("%s length = %d", str, len);

    return 0;
}