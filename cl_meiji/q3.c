//***************************************************
/** 第3回：アドレスとポインタ変数 */
//***************************************************

#include <stdio.h>

int main(void)
{
    //課題１ それぞれの型のアドレス確認、
    int a;
    float f;
    long l;
    char c;
    int d_arr[10];
    float f_arr[10];
    long l_arr[10];
    char c_arr[10];

    puts("address of data");
    printf("int ... [%d]\nfloat ... [%d]\nchar ... [%d]\n", &a, &f, &c);

    printf("d_arr[0] ... [%d]\n", &d_arr[0]);
    printf("d_arr[1] ... [%d]\n\n", &d_arr[1]);

    printf("f_arr[0] ... [%d]\n", &f_arr[0]);
    printf("f_arr[1] ... [%d]\n\n", &f_arr[1]);

    printf("l_arr[0] ... [%d]\n", &l_arr[0]);
    printf("l_arr[1] ... [%d]\n\n", &l_arr[1]);

    printf("c_arr[0] ... [%d]\n", &c_arr[0]);
    printf("c_arr[1] ... [%d]\n\n", &c_arr[1]);

    puts("----------------------------------------------------");

    //課題３ 値、addressの代入
    int x = 2, y = 3;
    int *px, *py;

    px = &x;
    py = &y;

    printf("px = [%d] [%d], py = [%d] [%d]\n", *px, px, *py, py);

    x = y;   //
    px = py; // px の指す先が y に変わる

    printf("px = [%d] [%d], py = [%d] [%d]\n", *px, px, *py, py);

    puts("----------------------------------------------------");

    // ポインタ変数の増減とメモリ
    int int_arr[5] = {10, 20, 30, 40, 50};
    int value;
    int *p; //この宣言時の型指定から、ポインタ変数を増減した際に何バイト先に進むかが決まる

    p = int_arr;

    printf("address : int_arr[0] = [%d]\n", p);
    printf("value : *p = [%d]\n", *p);

    p += 2; // ポインタ変数を２進めたので int_arr[2] を指す
    printf("value : *p = [%d]\n", *p);

    value = *(p - 1); //ポインタ変数を -1 したので int_arr[1] を指す
    printf("value : value = [%d]\n", value);

    puts("----------------------------------------------------");

    //課題４
    //整数型配列に初期値として，(10,20,30,40,50)を設定したとき，全ての要素の値を表示するプログラムをポインタを用いて作成

    int int_arr2[] = {10, 20, 30, 40, 50};
    int i, *i_p = int_arr2;

    for (i = 0; i < 5; i++)
    {
        printf("%d ", i_p[i]);
    }

    //ポインタと文字列
    char *pa = "ABC012";
    printf("%c\n", pa[0]); // A

    puts("----------------------------------------------------");

    //課題５
    //前回の課題３「キーボードから文字列を入力すると，何文字入力されたかを画面に表示するプログラムを作成せよ。」を，ポインタを用いて作成

    char input[100];
    char *p_c;
    int count = 0;

    p_c = input;

    printf("enter string >> ");
    scanf("%s", input);
    // scanf("%s", p_c);

    while (*p_c != '\n')
    {
        p_c++;
        count++;
    }

    printf("%d", count);

    return 0;
}