//***************************************************
/** テロップ表示（２：右方向へ文字を流す） */
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
    char name[] = "Pochi ";
    int name_len = strlen(name);

    while (1)
    {
        putchar('\r');

        for (i = 0; i < name_len; i++)
        {
            if (cnt + i < name_len)
            {
                putchar(name[cnt + i]);
            }
            else
            {
                putchar(name[cnt + i - name_len]);
            }
        }

        fflush(stdout);
        sleep(500);

        // 右方向へ文字が流れる
        // cntをデクリさせ、文字列後方から出力させていく
        if (cnt > 0)
        {
            cnt--;
        }
        else
        {
            cnt = name_len - 1; // 先頭文字から表示する
        }
    }

    return 0;
}

/*
forループにて（7回）
１：[Pochi ]
２：[ Pochi]
３：[i Poch]
４：[hi Poc]
５：[chi Po]
６：[ochi P]
７：[Pochi ]
*/