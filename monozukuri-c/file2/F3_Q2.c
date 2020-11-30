//***************************************************
/** ファイルから読み込み【fgetc／fgets／fscanfの使い方】
 * https://monozukuri-c.com/langc-file-read/
 * 課題２ fgets()
 * 11/30
 */
//***************************************************

#include <stdio.h>

#define D_STR_BUF_SIZE (256) //配列サイズをマクロ定義

int main(void)
{
    FILE *fp = fopen("SteveJobs.txt", "r");
    char str[D_STR_BUF_SIZE];
    int i, count = 0;

#if 0
    //自コード
    while ((fgets(str, sizeof(str), fp)) != NULL)
    {
        if (*str == '\0')
        {
            count++;
        }
        printf("Line%d:%s", count, str);
    }

#else
    //解答コード
    for (i = 1; fgets(str, D_STR_BUF_SIZE, fp) != NULL; i++)
    {
        printf("Line%d:%s", i, str);
    }

#endif

    return 0;
}