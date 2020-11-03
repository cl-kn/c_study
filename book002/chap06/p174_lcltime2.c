//***************************************************
/** 現在日付時刻を表示（asctime()の利用） */
//***************************************************

#include <stdio.h>
#include <time.h>

int main(void)
{
    // struct tm *tm;
    time_t current = time(NULL);
    printf("%s", asctime(localtime(&current)));

    return 0;
}