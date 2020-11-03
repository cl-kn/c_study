//***************************************************
/** カウントダウン後にプログラム実行時間を表示 */
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
    return 1;
}

int main(void)
{
    int i;
    clock_t c;

    printf("count down start\n\n");
    for (i = 10; i >= 0; i--)
    {
        printf("\r%2d", i);
        fflush(stdout);
        sleep(100);
        if (i == 0) {
            printf("aaaaaaa\n");
        }
    }

    printf("\n");
    c = clock();
    printf("\n%.1f秒経過\n", (double)c / CLOCKS_PER_SEC);

    return 0;
}