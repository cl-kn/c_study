//***************************************************
/** コマンドライン引数
 * PG名、PG仮引数の表示１
 */
//***************************************************

#include <stdio.h>

int main(int argc, char *argv[])
{
    int i;

    for (i = 0; i < argc; i++)
    {
        printf("argc = %d\n", argc);
        printf("argv[%d] = \"%s\"\n", i, argv[i]);
    }

    return 0;
}

/*
コマンドライン引数：main関数に渡す引数

int main(int argc, char *argv[])

argc：引数の総個数（PG名含む）
argv：引数の文字列を指す"ポインタの配列"を表す

*/