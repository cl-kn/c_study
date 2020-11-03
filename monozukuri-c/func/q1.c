//***************************************************
/**課題１
 * サイト：https://monozukuri-c.com/langc-function/
 * 10月29日
 */
//***************************************************

#include <stdio.h>

//三角形の面積を算出
unsigned long getAreaTriangle(unsigned long bottom, unsigned long height)
{
    unsigned long area = (bottom * height) / 2;
    return area;
}

int main(void)
{
    unsigned long bottom = 350;
    unsigned long height = 480;
    unsigned long area = getAreaTriangle(bottom, height);

    printf("底辺：%.0lu 高さ：%.0lu 面積：%.0lu\n", bottom, height, area);

    return 0;
}