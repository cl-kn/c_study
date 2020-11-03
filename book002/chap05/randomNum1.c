//***************************************************
/** ランダムな数値 */
//***************************************************

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
    srand((unsigned)time(NULL));

    int no;
    printf("\"RAND_MAX\" = %d\n\n", RAND_MAX); //32767までの乱数を生成

    puts("--------------------------------------------");

    for (int i = 0; i < 5; i++)
    {
        printf("[rand() %% 6 = %d]\n", rand() % 6); // 0～5までの乱数値を生成
    }

    puts("--------------------------------------------");

    for (int i = 0; i < 5; i++)
    {
        printf("[rand() %% 6 + 1 = %d]\n", rand() % 6 + 1); // 1～6までの乱数値を生成
    }

    puts("--------------------------------------------");

    for (int i = 0; i < 10; i++)
    {
        int no = rand() % 10; //０～９
        printf("%d, ", no);
    }

    puts("--------------------------------------------");

    for (int i = 0; i < 10; i++)
    {
        int no = rand() % 10 + 1; //１～１０
        printf("%d, ", no);
    }

    for (int i = 0; i < 5; i++)
    {
        printf("[rand() %% 9000 + 10000 = %d]\n", rand() % 9000 + 1000); // 1000～10000までの乱数値を生成
    }

    // printf("%d", no);

    return 0;
}