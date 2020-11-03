//***************************************************
/** 第7回：演習 (1),(2)
 * ファイル読み取り、書き込み
 */
//***************************************************

#include <stdio.h>
#include <stdlib.h>

void write_file(char *);
void read_file(char *);

int main(void)
{
    char filename[] = "ext_1.txt";

    // write_file(filename);
    read_file(filename);

    return 0;
}

//ファイルへ「1行」書き込みする関数
void write_file(char *file_name)
{
    char str[256];
    FILE *fp = fopen(file_name, "w");

    if (fp == NULL)
    {
        printf("*****file read failed*****\n");
    }

    printf("enter string >> ");
    scanf("%s", str);
    fprintf(fp, str);
    fclose(fp);
}

//ファイルを読み込み、表示する関数
void read_file(char *file_name)
{
    char str[100];
    FILE *fp = fopen(file_name, "r");

    if (fp == NULL)
    {
        printf("*****file does not exist*****\n");
        exit(1);
    }

    fscanf(fp, "%s", str);
    printf("%s", str); //exit(1)しない場合、str[100]の初期値が表示される（文字化け）
    fclose(fp);
}
