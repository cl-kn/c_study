//***************************************************
/** ポインタを使う手順【パターンで覚える４つのStep 】
 * https://monozukuri-c.com/langc-pointer-procedure/
 *
 * 11/8、11/9
 */
//***************************************************

#include <stdio.h>

//課題１：引数（底辺、高さ）：戻り値（なし）
void getAreaTriangle(unsigned short bottom, unsigned short height, unsigned long *pArea)
{
    *pArea = (bottom * height) / 2;
}

//課題２：引数（long型ポインタ）：戻り値（なし）
void convConsumptionTax(long *pPrice)
{
    long tax = *pPrice * 0.08;
    *pPrice = *pPrice + tax;
}

int main(void)
{
    //課題１：
    unsigned short bottom = 1200;
    unsigned short height = 380;
    unsigned long area;

    getAreaTriangle(bottom, height, &area);
    printf("底辺：%d 高さ：%d 面積：%d\n", bottom, height, area);

    //課題２：
    long price = 10000;

    convConsumptionTax(&price);
    printf("税込価格：%lu\n", price);

    return 0;
}
