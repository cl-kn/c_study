//***************************************************
/** 任意の個数を読み込み、要素数10の配列に最後の10個を格納 */
//***************************************************

#include <stdio.h>
#define MAX 10

int main(void)
{
    int i, array[MAX];
    int cnt = 0;
    int retry;

    printf("整数を入力してください\n");
    // printf("※ %d個まで ※\n", MAX);

    do
    {
        if (cnt >= MAX)
        {
            for (i = 0; i < MAX - 1; i++)
            {
                array[i] = array[i + 1];
            }
            printf("%d個目の整数：", cnt + 1);
            scanf("%d", &array[cnt < MAX ? cnt : MAX - 1]);
            cnt++;

            printf("続けますか？（Yes ... 1 / No ... 0）：");
            scanf("%d", &retry);
        }
    } while (retry == 1);

    // printf("%d個目の整数：", cnt + 1);
    // scanf("%d", &array[cnt++]);

    if (cnt <= MAX)
    {
        for (i = 0; i < cnt; i++)
        {
            printf("%2d個目：%d\n", i + 1, array[i]);
        }
    }
    else
    {
        for (i = 0; i < MAX; i++)
        {
            printf("%2d個目：%d\n", cnt - MAX + 1 + i, array[i]);
        }
    }

    return 0;
}