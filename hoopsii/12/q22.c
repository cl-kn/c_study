#include <stdio.h>
#include <string.h>

//***************************************************
/**
 * 第12回演習問題Ⅲ
 * ２：字列を複数入力して、逆順に表示するプログラム
 * 「END」と入力すると、プログラムを終了させる。
 * 表示を行うときには「END」を表示しない
 */
//***************************************************

// void printStr(char str[]);

int main(void)
{
    // 配列を用意
    char str[256][256];
    int i = 0;
    int j = 0;

    printf("文字を入力して下さい\n");

    // 無限ループ、入力値を配列に格納
    while (1)
    {
        printf(">> ");
        scanf("%s", str[i]);

        // 入力値がENDならば break
        if (strcmp(str[i], "END") == 0)
        {
            i--;
            break;
        }
        i++;
    }

    // 入力値を配列最後から順に表示
    for (i; i >= 0; i--)
    {
        printf("%s\n", str[i]);
    }
    return 0;
}

// int main(void)
// {
//     printf("文字を入力してください");

//     char str[256][256];
//     char check[] = "END";

//     for (int i = 0; i < 256; i++)
//     {
//         for (int j = 0; j < 256; j++)
//         {
//             scanf("%s", str[i][j]);
//             if (strcmp(str[i][j], check) == 0)
//             {
//                 break;
//             }
//         }
//     }

//     for (int i = 0; i < 256; i++)
//     {
//         for (int j = 0; j < 256; j++)
//         {
//             printf("%s\n", str[i][j]);
//         }
//     }

//     return 0;
// }

// void printStr(char str[])
// {
// }