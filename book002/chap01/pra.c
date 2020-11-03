//***************************************************
/** メモ */
//***************************************************

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int getRandom(int, int);

int main(void)
{
    int num1, num2;
    printf("１～１０までの値を入力して下さい\n>> ");
    scanf("%d", &num1);

    num2 = getRandom(1, 10);

    if (num1 == num2)
    {
        printf("数：%d 入力値：%d \n****当たり****\n", num2, num1);
    }
    else
    {
        printf("数：%d 入力値：%d \n****ハズレ****\n", num2, num1);
    }

    return 0;
}

int getRandom(int min, int max)
{
    srand(time(NULL));
    return rand() % max + min;

    // static int flag;

    // if (flag == 0)
    // {
    //     srand((unsigned int)time(NULL));
    //     flag = 1;
    // }

    // return min + (int)(rand() * (max - min + 1.0) / (1.0 + RAND_MAX));
}