#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#define NUM 3

//***************************************************
/**
 * 入力値を文字列で受け取り、整数に変換して値のチェックを行う
 */
//***************************************************

long median();

int main(void)
{
    median();

    return 0;
}

// ３値の中央値を求める、median関数
long median(void)
{
    int i, max, min, median; //使用する変数の宣言
    char buffer[NUM][256];     //入力値を一時格納する配列
    char *po;              //値チェック用ポインタ変数
    int array[NUM];          //チェック後の値を格納する配列

    printf("半角整数を3つ入力してください。\n");

    /** 入力値を受け取り、半角英字の場合は再度入力を促す処理 **/
    for (i = 0; i < NUM; i++)
    {
        printf("%dつ目 > ", i + 1);
        scanf("%s", buffer[i]);

        // strtol関数で、文字列を数値に変換
        array[i] = strtol(buffer[i], &po, 10);

        // 値チェック
        if ((errno != ERANGE) && (*po != '\0'))
        {
            printf("半角整数を入力してください。\n");
            i -= 1; //再度入力を促す為、カウント変数 i を１減らす
            continue;
        }
    }

    // 3値の最大値と最小値を変数 max , min にそれぞれ代入する
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

    // 中央値を変数 median に代入
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