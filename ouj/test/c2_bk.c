#include <stdio.h>

int main(void)
{
    // int x, y, z;
    int array[3];
    int i;
    int max, min, median;

    printf("整数を3つ入力してください。\n");
    for (i = 0; i < 3; i++)
    {
        printf("%dつ目 >> ", i + 1);
        scanf("%d", &array[i]);
    }

    min = max = median = array[0];
    for (i = 1; i < 3; i++)
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

    // ※※
    for (i = 0; i < 3; i++)
    {
        if (min < array[i] && array[i] < max)
        {
            median = array[i];
        }
    }

    printf("最高点：%d点\n", max);
    printf("最低点：%d点\n", min);
    printf("中央点：%d点", median);

    // printf("1つ目 > ");
    // scanf("%d", &x);

    // printf("2つ目 > ");
    // scanf("%d", &y);

    // printf("3つ目 > ");
    // scanf("%d", &z);

    // printf("中央値は %d です。", median(x, y, z));
    return 0;
}

//※※要改善※※
// int median(int x, int y, int z)
// {
//     int min = 0;
//     int max = 0;

//     for (int i = 0; i < 3; i++)
//     {
//         max =
//     }

//     if (x > y && x > z)
//     {
//         max = x;
//         if (y > z)
//         {
//             min = z;
//             return y;
//         }
//         else
//         {
//             min = y;
//             return z;
//         }
//     }
//     else if (y > x && y > z)
//     {
//         max = y;
//         if (x > z)
//         {
//             min = z;
//             return x;
//         }
//         else
//         {
//             min = x;
//             return z;
//         }
//     }
//     else if (z > x && z > y)
//     {
//         max = z;
//         if (x > y)
//         {
//             min = y;
//             return x;
//         }
//         else
//         {
//             min = x;
//             return y;
//         }
//     }
// }

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