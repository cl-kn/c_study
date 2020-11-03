//***************************************************
/**課題４
 * サイト：https://monozukuri-c.com/langc-function/
 * 10月29日
 */
//***************************************************

#include <stdio.h>

int count = 0;

void echoGreeting(void)
{
    if (count == 3)
    {
        count = 0;
    }

    switch (count)
    {
    case 0:
        printf("おはようございます\n");
        break;
    case 1:
        printf("こんにちは\n");
        break;
    case 2:
        printf("こんばんは\n");
        break;
    default:
        break;
    }
    count++;
}

int main(void)
{
    echoGreeting();
    echoGreeting();
    echoGreeting();
    echoGreeting();
    return 0;
}