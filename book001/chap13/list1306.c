//***************************************************
/** ファイルの中身を表示 */
//***************************************************

#include <stdio.h>

int main(void)
{
    int ch;
    FILE *fp;
    char fname[FILENAME_MAX];

    printf("ファイル名：");
    scanf("%s", fname);

    if ((fp = fopen(fname, "r")) == NULL)
    {
        printf("file open failed!!");
    }
    else
    {
        while ((ch = fgetc(fp)) != EOF)
        {
            putchar(ch);
        }
        fclose(fp);
    }

    return 0;
}