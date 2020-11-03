#include <stdio.h>
int func(int i, int j);

int main(void)
{
    int i;

    printf("---address----------------\n");
    printf("\tmain\t%p\n", main);
    printf("\tfunc\t%p\n", func);     // アドレス表示には、変換指定子 %p 使う
    printf("\tmain-i\t%p\n", &i); // & はアドレス演算子

    i = func(5, 3);

    return 0;
}

// func関数
int func(int i, int j)
{
    printf("\tfunc-i\t%p\n", &i);
    printf("\tfunc-j\t%p\n", &j);

    return i * j;
}