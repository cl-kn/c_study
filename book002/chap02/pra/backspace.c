//***************************************************
/** p36 の練習 */
//***************************************************

#include <stdio.h>
#include <string.h>
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
    char str[] = "(^^)/(^^)/(^^)/(^^)/(^^)/(^^)/(^^)/(^^)/(^^)/(^^)/(^^)/(^^)/(^^)/(^^)/(^^)/(^^)/(^^)/(^^)/";
    int str_len = strlen(str);
    printf("%s", str);

    for (i = 0; i < str_len; i++)
    {
        sleep(50);
        printf("\b \b");
        fflush(stdout);
    }

    return 0;
}