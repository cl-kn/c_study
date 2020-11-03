//***************************************************
/** テロップ表示（１：左方向へ文字を流す） */
//***************************************************

#include <time.h>
#include <stdio.h>
#include <string.h>

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
    int cnt = 0;
    // char name[] = "(`・ω・´)(`・ω・´)(`・ω・´)";
    char name[] = "Pochi ";
    int name_len = strlen(name); //6

    while (1)
    {
        putchar('\r'); //同じ行の先頭に戻る

        for (i = 0; i < name_len; i++)
        {
            if (cnt + i < name_len)
            {
                putchar(name[cnt + i]);
                // printf("\ncnt = %d\n",cnt);
            }
            else
            {
                putchar(name[cnt + i - name_len]);
            }
        }

        /* 1回目のループ：ここまでで、「Pochi 」が出力される */

        fflush(stdout); //掃きだし
        sleep(500);     //0.5秒経過させる

        //左方向へ文字が流れる
        if (cnt < name_len - 1)
        {
            cnt++;
        }
        else
        {
            cnt = 0;
        }
        // break;
    }

    return 0;
}

/*
forループにて（7回）
１：[Pochi ]
２：[ochi P]
３：[chi Po]
４：[hi Poc]
５：[i Pochi]
６：[ Pochi]
７：[Pochi ]
*/