//***************************************************
/** 現在の日付・時刻をファイルに出力する */
//***************************************************

#include <stdio.h>
#include <time.h>

int main(void)
{
    FILE *fp;
    time_t current = time(NULL);
    struct tm *timer = localtime(&current);

    if ((fp = fopen("dt_dat", "w")) == NULL)
    {
        printf("file open faild!!\n");
    }
    else
    {
        printf("現在の日付・時刻を書き出しました！");
        fprintf(fp, "%d %d %d %d %d %d\n", timer->tm_year + 1900, timer->tm_mon + 1, timer->tm_mday, timer->tm_hour, timer->tm_min, timer->tm_sec);
        fclose(fp);
    }

    return 0;
}