//***************************************************
/** https://www.cc.kyoto-su.ac.jp/~yamada/programming/pointer.html#inderection */
//***************************************************

#include <stdio.h>

// int return_p(int **);

int main(void)
{
    int x;

    int *pp; //int型ポインタ変数pの宣言
    pp = &x; //pにxのアドレスを代入

    *pp = 222;

    printf("%d\n\n", pp);

    printf("*pp = %d\n", *pp);
    printf("x = %d\n", x);

    printf("*pp address = %p\n", &pp);

    /*************************************************/
    //演習１
    int a, b, c;
    int *p = &a, *q = &b, *r = &c;

    *p = 3;
    *q = 5;
    *r = *p + *q;

    printf("a = %d\n", *p);
    printf("b = %d\n", *q);
    printf("a + b = %d\n", *r);

    /*************************************************/
    printf("\n*******************array & pointer*******************\n");

    int array[5];
    int *p_arr;
    int i;

    p_arr = array; // p_arr = array[0] と同じ

    for (i = 0; i < 5; i++)
    {
        p_arr[i] = i; // array[i] = i と同じ
    }

    for (i = 0; i < 5; i++)
    {
        printf("array[%d] = %d\n", i, array[i]);
    }

    /*************************************************/
    printf("\n******************* array & pointer 2 *******************\n");

    int array2[5];
    int *p_arr2;

    p_arr2 = &array2[2];

    for (i = -2; i < 3; i++)
    {
        //ポインタが指す要素から、足された（引かれた）数だけ後ろ（前）の要素を指す
        *(p_arr2 + i) = i; //最初、p_arr2[2] - 2 より、p_arr2[0]となる
    }

    for (i = 0; i < 5; i++)
    {
        printf("array2[%d] = %d\n", i, array2[i]);
    }
    printf("\n");

    /*************************************************/
    printf("\n******************* array & pointer 3 *******************\n");

    int array3[5];
    int *p_arr3;
    p_arr3 = array3;

    for (i = 0; i < 5; i++)
    {
        *p_arr3 = i;
        p_arr3++;
    }

    for (i = 0; i < 5; i++)
    {
        p_arr3--;
        printf("%d\n", *p_arr3);
    }

    printf("%d", p_arr3[1]);

    return 0;
}

// int return_p(int **p)
// {
//     // *p = 123;
//     return **p;
// }