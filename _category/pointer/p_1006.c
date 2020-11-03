//***************************************************
/** 「奇妙なキャストについて」より
 * https://qiita.com/Hattomo/items/9fcf213f40b669e1c24e
 */
//***************************************************

#include <stdio.h>

int main(void)
{
    //int型のポインタ int_a_p
    int int_a = 0;
    int *int_a_p = &int_a;

    //double型のポインタ double_a_p
    double double_a = 0;
    double *double_a_p = &double_a;

    //中身がint型か、double型か不明なポインタ p
    //型が不一致
    double *p = &int_a;

    int *p2 = &double_a;

    //ポインタの中身サイズを表示
    printf("int_a = %d\n", (int)sizeof(*int_a_p));
    printf("p = %d\n", (int)sizeof(*p));

    //ポインタの中身サイズを表示
    printf("double_a = %d\n", (int)sizeof(*double_a_p));
    printf("p2 = %d\n", (int)sizeof(*p2));

    //色々な型でキャスト
    printf("%p\n", int_a_p);
    printf("%p\n", (int *)int_a_p);
    printf("%p\n", (double *)int_a_p);

    return 0;
}