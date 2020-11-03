#include <stdio.h>

//***************************************************
/**
 *
 */
//***************************************************

void printTriangle(int);

int main(void)
{
    int num = 0;
    printf("段数を入力してください >> ");
    scanf("%d", &num);
    print_triangle(num);

    return 0;
}

void print_triangle(int n)
{
    // n段のループ
    for (int i = 0; i < n; i++)
    {

        // 空白表示ループ
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
print_triangle関数に、三角形を表示する処理をまとめる。
15行目：作成する段のループ
20行目：空白を表示するループ
27行目：「o」を表示するループ ※奇数分

*/