#include <stdio.h>

int func(int);

// 値渡しの確認プログラム
int main(void)
{
    int n = 1;

    printf("(1) n = %d\n", n); // 1

    func(n);

    printf("(4) n = %d\n", n); // 1

    return 0;
}

int func(int a)
{

    printf("(2) n = %d\n", a);

    a = 2;

    printf("(3) n = %d\n", a);

    return 0;
}
