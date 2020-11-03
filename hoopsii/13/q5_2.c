#include <stdio.h>

//***************************************************
/** 第13回
 * 簡易計算機に余りを求める関数を追加
 * 余りはポインタを利用する
 */
//***************************************************
int sum;
int add(int, int);                  //加算
int sub(int, int);                  //減算
int mul(int, int);                  //乗算
int div(int, int);                  //割り算
int div_re(int, int, int *, int *); //剰余

int main(void)
{
    int i, num, x, y, result;
    int *p1, *p2; //ポインタ変数

    //
    p1 = &x; //ポインタ変数に、ｘのアドレスを代入
    p2 = &y; // 〃

    while (1)
    {
        printf("簡易計算機\n");
        printf("加算=>1、減算=>2、乗算=>3、除算=>4、剰余=>5、終了=>0\n");

        printf("どの計算をしますか？ ==>");
        scanf("%d", &num);

        if (num == 0 || 5 < num)
        {
            printf("終了します");
            break;
        }

        printf("x >>");
        scanf("%d", &x);
        printf("y >>");
        scanf("%d", &y);

        switch (num)
        {
        case 1:
            result = add(x, y);
            printf("%d + %d = %d\n", x, y, result);

            break;
        case 2:
            result = add(x, y);
            printf("%d - %d = %d\n", x, y, result);

            break;
        case 3:
            result = add(x, y);
            printf("%d * %d = %d\n", x, y, result);

            break;
        case 4:
            result = add(x, y);
            printf("%d / %d = %d\n", x, y, result);
            break;
        case 5:
            // 入力値の[x,y]と[x,y]のポインタを関数div_reに引数として渡す(※戻り値なし)
            printf("%d ÷ %d = ", x, y);
            div_re(x, y, p1, p2); //関数内で[x,y]の値が書き換わる
            printf("%d 余り %d\n", x, y);
            break;
        default:
            printf("数値が正しくない。\n");
            break;
        }
    }
    return 0;
}

int add(int x, int y)
{
    sum = x + y;
    return sum;
}

int sub(int x, int y)
{
    sum = x - y;
}

int mul(int x, int y)
{
    sum = x * y;
}

int div(int x, int y)
{
    sum = x / y;
}

int div_re(int x, int y, int *i, int *n)
{
    *i = x / y;
    *n = x % y;
}