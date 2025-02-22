#include <stdio.h>
#define NUM 3

//***************************************************
/**
 * 「期末課題 C-2」3つの値の中央値を求める
 */
//***************************************************

int median(int []);

int main(void)
{
    int array[NUM];
    int i;
    int max, min;
    printf("整数を3つ入力してください。\n");
    for (i = 0; i < NUM; i++)
    {
        printf("%dつ目 > ", i + 1);
        scanf("%d", &array[i]);
    }

    median(array);

    return 0;
}

int median(int array[])
{
    int i;
    int max, min, median;

    min = max = median = array[0];
    for (i = 1; i < NUM; i++)
    {
        if (array[i] > max)
        {
            max = array[i];
        }
        if (array[i] < min)
        {
            min = array[i];
        }
    }

    for (i = 0; i < NUM; i++)
    {
        if (min < array[i] && array[i] < max)
        {
            median = array[i];
        }
    }

    printf("中央値は %d です。", median);

    return 0;
}

/*
期末課題 C-2 中央値------------------------------------------------------------------------------------
3つの整数を入力するとその中央値(大きさの順に並べたときの真ん中の値)を表示するプログラムを作ってください。 int型の値を3つ受け取り、その中央値をint型で返す関数median()を作って、それを使ってください[a]。

実行例1
整数を3つ入力してください。
1つ目 > 5
2つ目 > 3
3つ目 > 4
中央値は 4 です。
実行例2
整数を3つ入力してください。
1つ目 > 3
2つ目 > 3
3つ目 > 5
中央値は 3 です。
実行例3
整数を3つ入力してください。
1つ目 > 5
2つ目 > 4
3つ目 > 5
中央値は 5 です。
*/