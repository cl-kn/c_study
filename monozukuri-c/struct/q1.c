//***************************************************
/** 構造体
 * サイト：https://monozukuri-c.com/langc-struct/
 * 10月30日
 */
//***************************************************

#include <stdio.h>

typedef struct
{
    unsigned char hour; //時（０～２３）
    unsigned char min;  //分（０～５９）
    unsigned char sec;  //秒（０～５９）

} S_Time;

void printTime(S_Time time)
{
    printf("%d時%d分%d秒\n", time.hour, time.min, time.sec);
}

int main(void)
{
    S_Time time = {18, 28, 6};

    printTime(time);

    return 0;
}