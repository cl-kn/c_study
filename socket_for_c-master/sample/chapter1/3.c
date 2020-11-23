#include <stdio.h>

// 二つの返り値のある関数を作りたい
void swap(int *x_p, int *y_p)
{
    int w = *x_p;
    *x_p = *y_p;
    *y_p = w;
}

int main()
{
    int a = 3;
    int b = 10;
    swap(&a, &b);
    printf("a:%d,b:%d\n", a, b);
}