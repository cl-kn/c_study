//***************************************************
/** 10章のまとめ
 * 入力された点数を昇順に並び替える
*/
//***************************************************

#include <stdio.h>
#define NUM 5

void sort_score(int *p_array, int v)
{
    int i, j, temp;
    for (j = 0; j < v - 1; j++)
    {
        for (i = 0; i < (v - 1) - i; i++)
        {
            if (p_array[i] < p_array[i + 1])
            {
                temp = p_array[i];
                p_array[i] = p_array[i + 1];
                p_array[i + 1] = temp;
            }
        }
    }
}

// javaから
void sort_score2(int *p_array, int v)
{
    int i, j, temp;
    for (int i = 0; i < NUM - 1; i++)
    {
        for (int j = 0; j < (NUM - 1) - i; j++)
        {
            if (p_array[j] < p_array[j + 1])
            {
                temp = p_array[j];
                p_array[j] = p_array[j + 1];
                p_array[j + 1] = temp;
            }
        }
    }
}

int main(void)
{
    int i, array[NUM];
    printf("5人の点数を入力して下さい。\n");

    for (i = 0; i < NUM; i++)
    {
        printf("%d番 >> ", i + 1);
        scanf("%d", &array[i]);
    }

    sort_score(array, NUM);
    printf("降順にソートしました。\n");

    for (i = 0; i < NUM; i++)
    {
        printf("%d番 ： %d\n", i + 1, array[i]);
    }

    return 0;
}