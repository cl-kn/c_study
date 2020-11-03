#include <stdio.h>
#include <string.h>

//***************************************************
/**
 * 配列の全要素を０にする
 */
//***************************************************

void set_zero(int[], int);
void print_array(int[], int);

int main(void)
{
    int array1[5] = {1, 2, 3, 4, 5};
    int array2[3] = {2, 4, 6};

    printf("array1 = ");
    print_array(array1, 5);
    printf("array2 = ");
    print_array(array2, 3);

    set_zero(array1, 5);
    set_zero(array2, 3);

    printf("*************** array delete ***************\n");

    printf("array1 = ");
    print_array(array1, 5);
    printf("array2 = ");
    print_array(array2, 3);

    return 0;
}

// 配列の全要素に０を代入する
// n = 配列要素数
void set_zero(int v[], int n)
{

    for (int i = 0; i < n; i++)
    {
        v[i] = 0;
    }
}

void print_array(int v[], int n)
{
    printf("{");

    for (int i = 0; i < n; i++)
    {
        printf(" %d ", v[i]);
    }

    printf("}\n");
}