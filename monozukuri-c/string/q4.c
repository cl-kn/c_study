//***************************************************
/**  課題４ strcpy_s関数
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
    // char str2[len];

    strcpy(str, sizeof(str), "C learning");

    printf("%s\n", str);

    return 0;
}