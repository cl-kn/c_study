//***************************************************
/** 解答No.２ */
//***************************************************

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define DIGIT 4

int main(void)
{
    char digits[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'}; //選択用数値
    char num[5];                                                        //数値格納用配列
    int n = 10;
    int rand_num, i, j;

    srand(time(NULL));

    for (i = 0; i < DIGIT; i++)
    {
        rand_num = rand() % n;
        num[i] = digits[rand_num]; // 数値配列から値を選択
        n--;

        for (j = rand_num; j < n; j++)
        {
            digits[j] = digits[j + 1];
        }
    }

    num[DIGIT] = '\0';
    printf("%s\n", num);

    return 0;
}