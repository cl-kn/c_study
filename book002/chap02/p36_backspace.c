//***************************************************
/** 色々な書式
 * \b 「後退」
 * 表示位置が”その行内での直前の位置”に移動する
 */
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
    int i;
    printf("ABCDEFG");

    for (i = 0; i < 7; i++)
    {
        sleep(100);     //１秒ごとに
        printf("\b \b"); //後ろから１文字ずつ消す
        fflush(stdout);  //バッファを掃きだす
    }

    return 0;
}