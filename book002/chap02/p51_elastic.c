//***************************************************
/** 文字列を1文字ずつ消していく */
//***************************************************

#include <stdio.h>
#include <time.h>
#include <string.h>
#define STR_ARR 64

//xミリ秒経過を待つ
int sleep(unsigned long x)
{
    clock_t c1 = clock(), c2;

    do
    {
        //エラー
        if ((c2 = clock()) == (clock_t)-1)
        {
            return 0;
        }
    } while (1000.0 * (c2 - c1) / CLOCKS_PER_SEC < x);
}

int main(void)
{
    int i;
    char name[] = "PochiTamaShiro";
    int name_len = strlen(name);

    //文字列の表示ループ
    while (1)
    {
        //文字列を表示していく
        for (i = 0; i < name_len; i++)
        {
            putchar(name[i]);
            fflush(stdout);
            sleep(100);
        }

        //文字列を空白文字で1文字ずつ消す（上書き）
        for (i = 0; i < name_len; i++)
        {
            printf("\b \b");
            fflush(stdout);
            sleep(100);
        }

        // break;
    }

    return 0;
}