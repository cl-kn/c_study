//***************************************************
/**  課題１ 16進数の0x20～0xd7Eの値を文字で出力
 * https://monozukuri-c.com/langc-string-beginner
 * 10月30日
*/
//***************************************************

#include <stdio.h>

int main(void)
{
    char str;

    for (str = 0x20; str <= 0x7E; str++)
    {
        printf("%c ", str);
    }

    return 0;
}