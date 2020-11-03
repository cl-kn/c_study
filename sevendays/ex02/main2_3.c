#include <stdio.h>

void swap(int *, int *);
void swap2(int, int);

int main(void)
{
    int a = 1;
    int b = 2;

    printf("a = 1, b = 2\n", a, b);
    swap(&a, &b);
    printf("a = %d b = %d\n", a, b);

    int x = 1;
    int y = 2;

    printf("x = 1, y = 2\n", x, y);

    swap2(x, y);

    printf("x = %d y = %d\n", x, y);

    swap2(x, y);

    return 0;
}

// 値の入れ替え
// アドレスを入れ替えているので、値の入れ替えが関数外でも実現する
void swap(int *num1, int *num2)
{
    int temp = *num1;
    *num1 = *num2;
    *num2 = temp;
}

// 以下の関数内では、値の入れ替えは関数内でのみ行われ、main関数で定義したint型の値を引数に与えたとしても、値の変更は行われない
void swap2(int num1, int num2)
{
    printf("%d, %d\n", num1, num2);

    int temp2 = num1;
    num1 = num2;
    num2 = temp2;

    printf("%d, %d\n", num1, num2);
}