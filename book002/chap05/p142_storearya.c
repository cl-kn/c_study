//***************************************************
/** 最大10個の値を読み込んで要素数10の配列に格納 */
//***************************************************

#include <stdio.h>
#define MAX 10

int main(void)
{
    int i, array[MAX];
    int cnt = 0;
    int retry;

    printf("整数を入力してください\n");
    printf("※ %d個まで ※\n", MAX);

    do
    {
        printf("%d個目の整数：", cnt + 1);
        scanf("%d", &array[cnt++]);

        if (cnt == MAX)
        {
            break;
        }

        printf("続けますか？（Yes ... 1 / No ... 0）：");
        scanf("%d", &retry);

    } while (retry == 1);

    for (i = 0; i < cnt; i++)
    {
        printf("array[%2d]：%d\n", i , array[i]);
    }

    return 0;
}