#include <stdio.h>

void printTriangle(int);

int main(void)
{
    int num = 0;
    printf("please enter a number >>");
    scanf("%d", &num);
    printTriangle(num);

    return 0;
}

void printTriangle(int n)
{
    // n段のループ
    for (int i = 0; i < n; i++)
    {

        // 空白表示ループ
        // i初期値＝0の為、 i + 1
        for (int j = 0; j < n - (i + 1); j++)
        {
            printf(" ");
        }

        // 「o」の表示
        // k < (i + 1) * 2 - 1 奇数を表す
        for (int k = 0; k < (i + 1) * 2 - 1; k++)
        {
            printf("o");
        }
        printf("\n");
    }
}

/*
期末課題 B-2 二等辺三角形--------------------------------------------------------------------------------
“o”(小文字のオー)を使って、実行結果のような10段の二等辺三角形を描くプログラムを作ってください。 ソースコード中には、スペースを1つ表示する printf(" ") 、“o”を1つ表示する printf("o") 、改行を1つ表示する printf("\n") を、それぞれ1回だけ書くことができます。 練習課題22が参考になります。

実行結果
         O              空白18 空白（左から）9
        oOo             空白16 空白（左から）8
       ooOoo            空白14 空白（左から）7
      oooOooo           空白12 空白（左から）6
     ooooOoooo          空白10 空白（左から）5
    oooooOooooo         空白8  空白（左から）4
   ooooooOoooooo        空白6  空白（左から）3
  oooooooOooooooo       空白4  空白（左から）2
 ooooooooOoooooooo      空白2  空白（左から）1
oooooooooOooooooooo     空白0  空白（左から）0

・空白 n段-1
・oの数 1,3,5,7,9,11,13,15,17,19

・3段で作成する場合
  O     空白4
 oOo    空白2
ooOoo   空白0

※最中央「o」の位置は、作成するｎ段のｎである。

for文、while文、printf()、scanf()
*/

// int i, j, l, m;
// int x; // x段

// for ()
// {

//     while (x >= j)
//     {

//         if (j == x)
//         {
//             printf("o");
//         }
//         x--;
//     }
// }

// 段数を受け取り、二等辺三角形を表示する関数
// void printTriangle(int x)
// {
//     for (int i = 1; i <= x; i++)
//     {
//         for (int j = 0; j < x; (j = x - 1))
//         {
//             printf("o");
//         }
//         printf("\n");
//     }
// }