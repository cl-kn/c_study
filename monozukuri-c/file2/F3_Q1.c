//***************************************************
/** ファイルから読み込み【fgetc／fgets／fscanfの使い方】
 * https://monozukuri-c.com/langc-file-read/
 * 課題１ scanf(),toUpper_c()
 * 11/30
 */
//***************************************************

#include <stdio.h>

//小文字"1文字"を大文字へ変換する関数
void toUpper_c(char *c)
{
    if (*c >= 'a' && *c <= 'z')
    {
        *c -= 'a' - 'A';
    }
}

int main(void)
{
#if 1

    FILE *fp = fopen("Hello.txt", "r");
    char c;

    //ファイルから1文字読み込み、toUpper_c()を使用
    while ((c = fgetc(fp)) != EOF)
    {
        toUpper_c(&c);
        printf("%c", c);
    }

    fclose(fp);

#else

    char cc = 'b';
    printf("%c\n", toUpper_c(cc));

#endif

    return 0;
}