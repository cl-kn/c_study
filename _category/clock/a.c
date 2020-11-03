// timer.c 指定した秒数経過後に、メッセージを表示する
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void main(void)
{
    double startTime, endTime;
    double totalTime = 0.0, setTime = 0.0;
    char message[] = "時間だよ！";

    /* 時間をセット */
    printf("何秒にセットする？ ");
    scanf("%lf", &setTime);

    /* タイマー開始（ミリ秒単位） */
    startTime = clock() / CLOCKS_PER_SEC;

    while (1)
    {
        if (totalTime > setTime)
            break;
        endTime = clock() / CLOCKS_PER_SEC;
        totalTime = endTime - startTime;
    }
    printf("%s\n", message);

    printf("\nstartTime = %f\n", startTime);
    printf("endTime = %f\n", endTime);
    printf("totalTime = %f\n", totalTime);
}