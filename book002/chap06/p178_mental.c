//***************************************************
/** 暗算能力チェック
 * ０～９９の変数を4つ加算するのに要する時間を測定
 */
//***************************************************

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
    int a, b, c, d;
    int x;
    time_t start, end;
    srand(time(NULL));

    a = rand() % 100; // 0 - 99の乱数生成
    b = rand() % 100; //        〃
    c = rand() % 100; //        〃
    d = rand() % 100; //        〃

    printf("%d + %d + %d + %d = ?\n", a, b, c, d);

    start = time(NULL);

    while (1)
    {
        printf(">> ");
        scanf("%d", &x);
        if (x == (a + b + c + d))
        {
            break;
        }
        printf("failed....please retry a number");
    }

    end = time(NULL);

    printf("time : %.0f(sec)\n", difftime(end, start));

    return 0;
}