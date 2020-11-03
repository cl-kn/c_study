//***************************************************
/** はてな より */
//***************************************************

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define DIGIT 4

int main(void)
{
    int i, j;
    int pos = 0;
    int num[3];
    int rand_num;
    int flag;

    srand(time(NULL));

    while (pos < DIGIT)
    {
        rand_num = rand() % 10;

        //ループ１
        for (i = 0; i < DIGIT; i++)
        {
            // 数値の重複、比較開始
            if (num[i] == rand_num)
            {
                flag = 1;
                break;
            }
            if (flag == 1)
            {
                num[pos] = rand_num;
                pos++;
            }
            else
            {
                num[i] = rand_num;
                flag = 0;
            }
        }
    }

    for (j = 0; j < DIGIT; j++)
    {
        printf("%d", num[j]);
    }
    printf("\n");

    return 0;
}