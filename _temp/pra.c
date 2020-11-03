#include <stdio.h>

void showStatic();

int main(void)
{
    // int x = 1;
    // int y = 2;

    // // コンマ演算子
    // int check = (x == 1, y == 12);

    // printf("%d", check);

    // int i, j, k, n; /* ループ制御用変数 */

    // printf("段数を入力＞");
    // scanf("%d", &n);

    // for (i = 1; i <= n; i++)
    // { /* 縦のループ */

    //     for (j = 1; j <= n - i; j++)
    //     {
    //         printf(" "); /* 「 」の表示 */
    //     }

    //     for (k = 1; k <= 2 * i - 1; k++)
    //     {
    //         printf("*"); /* 「*」の表示 */
    //     }
    //     printf("\n"); /* 横一列書き終わったら改行 */
    // }

    // 構造体について
    // struct animal
    // {
    //     /* data */
    //     char name[20];
    //     char type[20];
    //     int age;
    // };

    showStatic(); // s = 100
    showStatic(); // s = 101

    // 文字列の配列
    char strArray[3] = {'A', 'b', 'C'};
    printf("%s\n", strArray);

    int arr[] = {1, 2, 3, 4, 5};

    printf("arr配列の要素数 [%d]", sizeof(arr) / sizeof(arr[0]));

    return 0;
}

void showStatic()
{
    // 2回目以降、呼ばれない
    // 静的変数の宣言と初期化
    static int s = 100;
    printf("s = %d \n", s);
    s++; // 静的変数のインクリメント
}