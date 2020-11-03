//***************************************************
/** ファイル入力 */
//***************************************************

#include <stdio.h>
#define LEN 64

int main(void)
{
    FILE *fp;
    char filename[LEN];

    printf("ファイル名を入力して下さい\n");
    scanf("%s", filename);

    fp = fopen(filename, "r");

    if (fp == NULL)
    {
        printf("file open failed !!");
    }
    else
    {
        printf("file open success !!");
    }

    fclose(fp);

    return 0;
}