//***************************************************
/** 第7回：演習 (1),(2)
 * ファイル読み取り、書き込み
 */
//***************************************************

#include <stdio.h>
#include <math.h> //sin関数利用

void write_file(char *);

int main(void)
{
    char filename[] = "rad.txt";

    // double rad, pi;
    // double x;
    // double i;

    // pi = 3.141; //πの定義
    // rad = 2.0 / 180.0 * pi;

    // for (i = 0.0; i <= 360.0; i++)
    // {
    //     rad = i / 180.0 * pi;
    // }

    // x = sin(rad);
    // printf("10 degrees ... sin %1.6f\n", x);

    return 0;
}

//ファイルへ「1行」書き込みする関数
void write_file(char *file_name)
{
    double str[360][256];
    FILE *fp = fopen(file_name, "w");

    if (fp == NULL)
    {
        printf("*****file read failed*****\n");
    }

    double rad, pi;
    double x;
    double i;
    int i = 0;

    pi = 3.141; //πの定義
    rad = 2.0 / 180.0 * pi;

    for (i = 0.0; i <= 360.0; i++)
    {
        rad = i / 180.0 * pi;
        x = sin(rad);
        str[i] = x;
            }

    printf("10 degrees ... sin %1.6f\n", x);

    printf("enter string >> ");
    scanf("%s", str);
    fprintf(fp, str);
    fclose(fp);
}

/*

str[360][256]
360個の要素にsinの値を格納

1
2
3
4
5
6



*/