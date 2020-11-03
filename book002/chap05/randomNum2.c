//***************************************************
/** ランダムな数値：同じ数字を使わない？？ */
//***************************************************

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
    srand(time(NULL));
    int i, j;
    int no[4];

    no[0] = rand() % 9 + 1;
    no[1] = rand() % 9 + 1;
    no[2] = rand() % 9 + 1;
    no[3] = rand() % 9 + 1;

    for (i = 0; i < 4; i++)
    {
        no[i] = rand() % 9 + 1;
        for (j = 0; j < i; j++)
        {
            if ()
            {
            }
        }
    }

    //配列no 表示用
    for (i = 0; i < 4; i++)
    {
        printf("%d", no[i]);
    }

    puts("\n----------------------------------------");

    return 0;
}