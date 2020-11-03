#include <stdio.h>

void show(int, int, int);

int main(void)
{
    int a = 100;
    int b = 200;
    int *p = NULL; // 慣例：ポインタ変数はNULLで初期化

    p = &a;         // pにaのアドレスを代入
    show(a, b, *p); // a = 100, b = 200, p = 100

    *p = 300;       // *pに値を代入
    show(a, b, *p); // a = 300, b = 200, p = 300

    p = &b;         // p にb のアドレスを代入
    show(a, b, *p); // a = 300, b = 200, p = 200

    *p = 400;       // *pに値を代入
    show(a, b, *p); // a = 300, b = 400, p = 400

    return 0;
}

void show(int n1, int n2, int n3)
{
    printf("a = %d b = %d *p = %d\n", n1, n2, n3);
}

// ポインタは透明な変数のように、コピー機能を持つものとして振舞う？
// 他の変数になりきれる