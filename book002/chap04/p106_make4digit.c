//***************************************************
/** ４つの数字の並びを生成して、配列xに格納 */
//***************************************************

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int make4digit(int x[])
{
    srand(time(NULL));

    int i, j, val;

    //[x,y,l,m]の４つの値を生成していく
    // ４回のfor文と、それぞれの値の生成
    for (i = 0; i < 4; i++)
    {
        do
        {
            val = rand() % 10; //０～９までの乱数生成
            for (j = 0; j < i; j++)
            {
                //同じ値の場合は、breakして再度乱数生成
                if (val == x[j])
                {
                    break;
                }
            }
        } while (j < i);
        x[i] = val;
    }
}

int main(void)
{
    int x[4];
    make4digit(x);

    printf("x[] = ");
    for (int i = 0; i < 4; i++)
    {
        printf("%d", x[i]);
    }

    return 0;
}