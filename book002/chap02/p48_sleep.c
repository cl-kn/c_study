//***************************************************
/** xミリ秒経過を待つ */
//***************************************************

#include <stdio.h>
#include <time.h>

//xミリ秒経過を待つ
int sleep(unsigned long x)
{
    clock_t c1 = clock(), c2;

    do
    {
        //clock_t()は
        //エラー時に、(clock_t)-1 ※(clock_t)型でキャストされた-1
        //を返す為、エラーが出たら処理停止
        if ((c2 = clock()) == (clock_t)-1)
        {
            return 0;
        }
    } while (1000.0 * (c2 - c1) / CLOCKS_PER_SEC < x);
}

int main(void)
{
    return 0;
}