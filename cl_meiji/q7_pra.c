//***************************************************
/** 7章：練習用 */
//***************************************************

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void write_file(char *);
void read_file(char *);

int main(void)
{
    char filename[] = "q7_pra.txt";

    write_file(filename);
    // read_file(filename);

    return 0;
}

//ファイルへ「1行」書き込みする関数
void write_file(char *file_name)
{
    char data[] = "puts test-pro";

    double rad, pi = 3.141;
    double x,i = 0.0;
    int count = 0;

    FILE *fp = fopen(file_name, "w");

    if (fp == NULL)
    {
        printf("*****file read failed*****\n");
        exit(1);
    }

    while (count <= 360)
    {
        rad = i / 180.0 * pi;
        x = sin(rad);

        fprintf(fp, "%f\n", x);

        i++;
        count++;
    }

    // fprintf(fp, "No.%d data.%s\n", number, data);

    // printf("enter string >> ");
    // scanf("%s", str);
    // fprintf(fp, str);
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
        puts("aaaaaaaaaa");
    }

    fscanf(fp, "%s", str);
    printf("%s", str);
    fclose(fp);
}
