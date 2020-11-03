#include <stdio.h>

/*****************************
 * 配列
*****************************/

int main(void)
{
    int n = 0, sum = 0, avg = 0;
    int t[5];

    printf("数値を５つ入力して下さい\n");

    for (n = 0; n < 5; n++)
    {
        printf("%d個目の数値を入力してください = ", n + 1);
        scanf("%d", &t[n]);

        sum += t[n];
    }

    avg = sum / 5;
    printf("平均値%d\n", avg);

    printf("5番目の入力値 = %d", t[4]);

    return 0;
}