//***************************************************
/** 暗算トレーニング（３桁の整数を３つ加える） */
//***************************************************

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main(void)
{
    int a, b, c;
    int inputNum;
    clock_t start, end;
    double req_time;

    srand(time(NULL));

    a = 1 + rand() % 100;
    b = 1 + rand() % 100;
    c = 1 + rand() % 100;

    printf("%d + %d + %d = ?\n", a, b, c);

    start = clock(); //測定開始

    while (1)
    {
        scanf("%d", &inputNum);
        if (inputNum == a + b + c)
        {
            break;
        }
        else
        {
            puts("false....please return number!!");
        }
    }

    end = clock();                                     //測定終了
    req_time = (double)(end - start) / CLOCKS_PER_SEC; //経過時間

    printf("time:%.1f(s)\n", req_time);

    if (req_time > 30.0)
    {
        puts("bad time...");
    }
    else if (req_time > 15.0)
    {
        puts("good");
    }
    else if (req_time > 5)
    {
        puts("so good");
    }
    else
    {
        puts("GOD");
    }

    return 0;
}