//***************************************************
/** ポーリングループで監視 */
//***************************************************

#include <stdio.h>

int main(void)
{
    // レジスタアドレスへのポインタ変数
    unsigned short *regA = (unsigned short *)0xB8000040;

    //最下位ビットをポーリングで監視
    while ((*regA & -0x0001) == 0x0000)
    {
        printf("regA = 0x%04x\n", *regA);
    };

    funcWhenBitSet();
    return 0;
}