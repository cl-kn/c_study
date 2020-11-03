//***************************************************
/** 第6回
 * （４）入力文字数のカウント
 */
//***************************************************

#include <stdio.h>
#define NUM 64

int count_str(char *);

int main(void)
{
    // char str[NUM];
    char str[] = "aiueo";
    // char *p_str;

    // p_str = str;

    // printf("enter strings...\n>> ");
    // scanf("%s", str);

    printf("[%s]\n", str);
    printf("string count [%d]", count_str(str));

    return 0;
}

int count_str(char *str)
{
    int count = 0;

    while (str[count] != '\n')
    {
        // str++;
        count++;
    }
    printf("%d", count);

    return count;
}
