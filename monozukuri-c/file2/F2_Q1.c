//***************************************************
/**ファイルへの書き込み【fputc／fputs／fprintfの使い方】
 * https://monozukuri-c.com/langc-file-write/
 * 課題１
 * 11/27*/
//***************************************************

#include <stdio.h>

int main(void)
{
    FILE *fp = NULL;
    int i, j;

    if ((fp = fopen("num.txt", "w")) != EOF)
    {
        for (i = 1; i <= 9; i++)
        {
            for (j = 1; j <= i; j++)
            {
                //ASCIIコードの'0'を元に数値を数字に変換
                fputc('0' + i, fp);
            }
            fputc('\n', fp);
        }
    }
    else
    {
        printf("EOF");
    }

    return 0;
}