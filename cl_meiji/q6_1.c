//***************************************************
/** 第６回：関数まとめ
 * (1) swap()関数の作成
*/
//***************************************************

#include <stdio.h>

void swap(float *, float *);

int main(void)
{
    float a = 2.0, b = 3.0;
    // float *pa, *pb;
    // pa = &a;
    // pb = &b;

    printf("a = %f, b = %f\n", a, b);

    swap(&a, &b);
    printf("a = %f, b = %f\n", a, b);

    return 0;
}

//（１）値の入れ替え関数
void swap(float *px, float *py)
{
    float value;

    value = *px;
    *px = *py;
    *py = value;
}
