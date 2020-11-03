//***************************************************
/**  */
//***************************************************

#include <stdio.h>

int main(void)
{
    int ch;
    FILE *fp;
    char fname[FILENAME_MAX];

    printf("file name >>");
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