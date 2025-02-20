#include <stdio.h>
#include <string.h>

//***************************************************
/**
 * 第12回演習問題Ⅲ 解答
 * ２：字列を複数入力して、逆順に表示するプログラム
 * 「END」と入力すると、プログラムを終了させる。
 * 表示を行うときには「END」を表示しない
 */
//***************************************************

int main(void)
{
    //2次元配列strの宣言
    char str[256][256];
    int i = 0;

    printf("文字を入力\n");

    //無限ループ
    while (1)
    {
        //i番目の配列に文字列を格納
        scanf("%s", str[i]);
        //"END"の場合にループ脱出
        if (strcmp(str[i], "END") == 0)
        {
            //ENDを表示させないように i を減らす
            i--;
            break;
        }
        i++;
    }

    printf("---------------入力値を逆順に表示---------------\n");
    for (i; i >= 0; i--)
    {
        printf("%s\n", str[i]);
    }

    return 0;
}