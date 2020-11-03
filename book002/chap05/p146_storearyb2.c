//***************************************************
/** 最大10個の値を読み込んで要素数10の配列に格納（改良版：配列の循環） */
//***************************************************

#include <stdio.h>
#define MAX 10

int main(void)

{
    int i, array[MAX];
    int cnt = 0;
    int retry;

    printf("%d個までの整数を入力してください。\n", MAX);

    do
    {
        printf("%d個目の個数 ", cnt + 1); // cntの値は変動しない

        //
        scanf("%d", &array[cnt++ % MAX]); //剰余の余りを利用して、10個以上の配列の格納を実現

        printf("続けますか？（Yes... 1 / No... 2）\n>> ");
        scanf("%d", &retry);
    } while (retry == 1);

    //10個以上 i >= 0、10個未満 i < 0
    i = cnt - MAX;

    //iが10個未満のとき
    if (i < 0)
    {
        i = 0;
    }

    for (i; i < cnt; i++)
    {
        printf("array[%2d] : %d\n", i, array[i % MAX]);
    }
    return 0;
}