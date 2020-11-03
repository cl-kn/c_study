#include <stdio.h>
#define NUM 5 //配列の要素数

//***************************************************
/**
 * 配列の受け渡し
 * ２科目の点数の最高点を求める
 */
//***************************************************

int max_of(int[], int);

int main(void)
{
    int i;
    int eng[NUM];
    int math[NUM];
    int max_e, max_m;

    printf("%d人の点数を入力して下さい\n", NUM);
    for (i = 0; i < NUM; i++)
    {
        printf("[%d] 英語：", i + 1);
        scanf("%d", &eng[i]);

        printf("[%d] 数学：", i + 1);
        scanf("%d", &math[i]);
    }

    max_e = max_of(eng, NUM);
    max_m = max_of(math, NUM);

    printf("英語の最高点 = %d\n", max_e);
    printf("数学の最高点 = %d", max_m);

    return 0;
}

int max_of(int v[], int n)
{

    int i;
    int max = v[0];

    for (i = 1; i < n; i++)
    {
        if (v[i] > max)
        {
            max = v[i];
        }
    }
    return max;
}