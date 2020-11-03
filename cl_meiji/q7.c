//***************************************************
/** 第7回：ファイル入出力 */
//***************************************************

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    char filename[100];
    FILE *fp;

    printf("enter file name >> ");
    scanf("%s", filename);

    /** ファイルモード
     * "r"      読み込み専用 read
     * "w"      書き込み専用 write
     * "rw"     読み取り＆書き込み read and write
     * "a"      追加書き込み（既知のファイル末尾に追加 or ファイルがないと新規作成） append
    */
    fp = fopen(filename, "w");

    if (fp == NULL)
    {
        exit(1);
    }

    fprintf(fp, "tiny corgi dog !!\n"); //ファイルに文字列を書きだす
    fprintf(fp, "%d\n", 10);            //ファイルに整数を書きだす
    fprintf(fp, "%f\n", 3.1415);        //ファイルに実数を書きだす

    fclose(fp);

    fp = fopen(filename, "r");

    int i;
    char input_file_str[100];
    fscanf(fp, "%d", &i);
    fscanf(fp, "%s", input_file_str);

    printf("%d\n", i);
    printf("%s\n", input_file_str);

    fclose(fp);

    return 0;
}