//***************************************************
/** 演習2-2
 * 文字列を先頭から1文字ずつ表示する関数
*/
//***************************************************

#include <stdio.h>
#include <time.h>
#include <string.h>

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

//*s 表示する文字列
//speed 表示速度
void gput(const char *s, int speed)
{
    int i;
    int s_len = strlen(s);

    for (i = 0; i < s_len; i++)
    {
        putchar(s[i]);
        fflush(stdout);
        sleep(speed);
    }
}

int main(void)
{
    // char *s = "aiueo";
    gput("abc", 1000);
    return 0;
}
