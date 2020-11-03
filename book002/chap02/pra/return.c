//***************************************************
/** P38 returnの練習 */
//***************************************************

#include <stdio.h>
#include <time.h>

//xミリ秒経過を待つ
int sleep(unsigned long x)
{
    clock_t c1 = clock(), c2;

    do
    {
        //エラーキャッチ
        if ((c2 = clock()) == (clock_t)-1)
        {
            return 0;
        }
    } while (1000.0 * (c2 - c1) / CLOCKS_PER_SEC < x);
}

int main(void)
{
    printf("shiba");
    fflush(stdout);

    sleep(1000);

    printf("\rcorgi");
    fflush(stdout);

    sleep(1000);

    printf("\rhusky");
    return 0;
}