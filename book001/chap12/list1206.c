//***************************************************
/** 構造体を返す関数 */
//***************************************************

#include <stdio.h>

typedef struct xyz
{
    int x;
    long y;
    double z;
}XYZ;

struct xyz xyz_of(int x, long y, double z)
{
    XYZ temp;

    temp.x = x;
    temp.y = y;
    temp.z = z;

    // 戻り値はtempの全メンバ
    return temp;
}

int main(void)
{
    XYZ value = {0, 0, 0};

    value = xyz_of(12, 928402, 3.1415);

    printf("xyz.x = %d\n", value.x);
    printf("xyz.y = %ld\n", value.y);
    printf("xyz.z = %f\n", value.z);

    return 0;
}