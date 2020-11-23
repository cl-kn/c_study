#include <stdio.h>

int main()
{
    int a = 3;
    // &: アドレス演算子 オペランドのポインタを返す
    int *p = &a;
    a++;
    printf("%d\n", a);
    // *: 間接演算子 オペランドの指し示す先のオブジェクトを返す。
    printf("%d\n", *p);
    // pのアドレスをみてみる
    printf("pのアドレス:%p\n", p);
}