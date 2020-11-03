#include <stdio.h>
int main(void)
{
    int x = 1;
    int y = 2;


    // int i = (x == 2, y == 1);// 0
    // int i = (x == 1, y == 2);// 1
    int i = (x == 0, y == 2);// 1


    printf("%d",i);

    return 0;
}

/*
コンマ演算子

i = (3, 5);

上記式では、３⇒５の順に評価され、５を評価して得られたint型：５が、
式 3, 5 を評価した値になる。
演算子の優先度：降順
()
=

*/