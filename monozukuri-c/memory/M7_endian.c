//***************************************************
/** エンディアン【通信やファイルの読み書きで必須の知識！】
 * https://monozukuri-c.com/langc-endian/
 * 11/17
 */
//***************************************************

#include <stdio.h>

int main(void)
{
    short num = 0x1234;
    return 0;
}

/**「エンディアン」
 * ・2バイト以上で表現される数値の、メモリへの格納方式
 * ・ある数をメモリにどう保管するか決めるルール
 * 
 * ビッグエンディアン方式
 * short num = 0x1234; → 0x12 , 0x34 (1Byteに数値を分割し、1Byte単位で収納)
 * 
 * リトルエンディアン方式
 * ・数値の下位バイトから順に格納する
 * short num = 0x1234; → 0x34 , 0x12 (1Byteに数値を分割し、1Byte単位で収納 ※順番が逆転)
 * 
*/