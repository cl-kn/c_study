//***************************************************
/** 「ポインタのポインタ」を図解
 * https://monozukuri-c.com/langc-pointer-to-pointer/
 * 11/12
 */
//***************************************************

#include <stdio.h>

int main(void)
{
    int num1 = 110;

    //ポインタ変数の定義
    int *p_num1 = &num1;
    int **pp_num1 = &p_num1;

    printf("num1 = %d\n",num1);
    printf("%d\n",p_num1);
    printf("%d\n",pp_num1);

    *p_num1 = 200;
    printf("num1 = %d\n",num1);

    **pp_num1 = 100;
    printf("num1 = %d\n",num1);

    return 0;
}

/**
 * 「ポインタのポインタ（ダブルポインタ）」
 * ・ポインタ変数を参照しているポインタ変数
 * ・ポインタ変数との違いは、参照先メモリのデータ型が異なる点
 *
 * [➀] [➁] [➂]
 * [char] [*] [pnum;]       ポインタ変数定義
 * [char *] [*] [ppnum;]    ダブルポインタ変数定義
 *
 * ➀ポインタが参照する先のデータ型
 * ➁ ➀に対してのデータ型
 * ➂ 変数名
*/