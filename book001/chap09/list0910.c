//***************************************************
/** 数字文字の出現回数
 * 文字列内の数字文字をカウントする
 */
//***************************************************

#include <stdio.h>

void str_count(const char s[], int count[])
{

    int i = 0;

    while (s[i])
    {

        if ((s[i] >= '0') && (s[i] <= '9'))
        {
            count[s[i] - '0']++;
        }
        i++;
    }
}

int main(void)
{
    int i;
    int dcount[10] = {0};
    char str[128];

    printf("文字列を入力して下さい：");
    scanf("%s", str);

    str_count(str, dcount);

    printf("数字文字の出現回数\n");

    for (i = 0; i < 10; i++)
    {
        printf("'%d' : %d\n", i, dcount[i]);
    }

    return 0;
}