//***************************************************
/**  関数ポインタ【ポインタを使って関数を呼ぶ仕組み解説】
 * https://monozukuri-c.com/langc-funcpointer/
 *
 * 課題２
 * 11/12
*/
//***************************************************

#include <stdio.h>

void addition(long, long);
void subtraction(long, long);
void multiplication(long, long);
void division(long, long);

typedef void (*FP_CALCULATION)(long, long);

int main(void)
{
    // 関数ポインタの配列
    FP_CALCULATION pfunc[] = {
        addition,       //加算
        subtraction,    //減算
        multiplication, //乗算
        division};      //除算

    int i;

    for (i = 0; i < sizeof(pfunc) / sizeof(pfunc[0]); i++)
    {
        pfunc[i](150,30);
    }

    return 0;
}

void addition(long num1, long num2)
{
    printf("%d + %d => %d\n", num1, num2, num1 + num2);
    return;
}
void subtraction(long num1, long num2)
{
    printf("%d - %d => %d\n", num1, num2, num1 - num2);
    return;
}

void multiplication(long num1, long num2)
{
    printf("%d * %d => %d\n", num1, num2, num1 * num2);
    return;
}

void division(long num1, long num2)
{
    printf("%d / %d => %d\n", num1, num2, num1 / num2);
    return;
}