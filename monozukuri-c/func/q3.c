//***************************************************
/**課題３
 * サイト：https://monozukuri-c.com/langc-function/
 * 10月29日
 */
//***************************************************

#include <stdio.h>

void displaySquare(unsigned short len)
{
    int i, j;
    // int count = len;

    // while(1) {

    //     printf();
    //     len--;

    //     if (len == 0) {
    //         break;
    //     }

    // }

    for (i = 0; i < len; i++)
    {
        // printf("#");
        for (j = 0; j < len; j++)
        {
            printf("#");
        }
        puts("\n");
    }
}

int main(void)
{
    displaySquare(3);

    return 0;
}