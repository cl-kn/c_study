#include <stdio.h>

// 二つの返り値のある関数を作りたい
void swap(int x, int y)
{
    int w = x;
    x = y;
    y = w;
}

int main()
{
    int a = 3;
    int b = 10;
    swap(a, b);
    printf("a:%d,b:%d\n", a, b);
}