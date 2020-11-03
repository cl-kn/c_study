//***************************************************
/** ファイルのコピー */
//***************************************************

#include <stdio.h>

int main(void)
{
    int ch;
    FILE *fp_be, *fp_af;
    char fname_be[FILENAME_MAX];
    char fname_af[FILENAME_MAX];

    printf("コピー元ファイル名 >> ");
    scanf("%s", fname_be);
    printf("コピー先ファイル名 >> ");
    scanf("%s", fname_af);

    if ((fp_be = fopen(fname_be, "r")) == NULL)
    {
        printf("file open failed !!!");
    }
    else
    {
        if ((fp_af = fopen(fname_af, "w")) == NULL)
        {
            printf("file open failed !!!");
        }
        else
        {
            while ((ch = fgetc(fp_be)) != EOF)
            {
                fputc(ch,fp_af);
            }
            fclose(fp_be);
        }
        fclose(fp_af);
    }

    return 0;
}