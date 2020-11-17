//***************************************************
/** エンディアン【通信やファイルの読み書きで必須の知識！】
 * https://monozukuri-c.com/langc-endian/
 * 課題
 * 11/17
 */
//***************************************************

#include <stdio.h>
#include <string.h>

//  ビッグエンディアンで並んだ0x0123と0x89ABCDEFのデータ
const static unsigned char data[] = { 0x01, 0x23, 0x89, 0xAB, 0xCD, 0xEF };

int main(void)
{
    unsigned short num1 = 0; //0x0123
    unsigned short num2 = 0; //0x89ABCDEF

    memcpy(&num1,data,2);

    printf("%x",num1);

    return 0;
}