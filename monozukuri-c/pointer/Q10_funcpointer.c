//***************************************************
/**  関数ポインタ【ポインタを使って関数を呼ぶ仕組み解説】
 * https://monozukuri-c.com/langc-funcpointer/
 * 11/12
 *
*/
//***************************************************

#include <stdio.h>

//引数を足し、出力する関数
long func(long num1, long num2)
{
    printf("%d\n", num1 + num2); //結果を画面に出力
    return num1 + num2;
}

//関数ポインタを引数に持つ関数 ※typedef未使用
void sub1(long (*pfunc)(int, short), int num)
{
    return;
}

//※typedefで関数ポインタの型を見やすく！
//関数ポインタ型を別名でtypedefする
typedef long (*FP_FUNC)(int, short);

void sub2(FP_FUNC pfunc, int num)
{
    return;
}

int main(void)
{
    //関数ポインタの変数定義
    long (*p_func)(long, long);

    func(100, 200); // 通常の関数呼び出し

    p_func = func; // 昇順設定 p_func --> func関数

    p_func(100, 200); // p_funcから関数呼び出し

    printf("func address(16) = %p\n", func);
    printf("p_func address(16) = %p\n", p_func);

    //*********************************************
    //関数ポインタの複雑さ*************************

    long (*p_func_sub)(int, short) = NULL; // 関数ポインタ
    sub1(p_func_sub, 100);                  //関数ポインタを引数で関数に渡す

    //typedef利用版
    FP_FUNC p_func_sub2 = NULL;
    sub2(p_func_sub2,100);

    return 0;
}

/**「関数ポインタ」
 * ・メモリ上に存在する「関数」を参照しているポインタ
 * ・関数を変数に保存して、利用できる
 *
 * 「定義方法」
 * long (*pfunc) (int, char);
 *
 * [➂][➁][➀][➃]
 * [long] ([*] [pfunc]) [(int, char)]
 *
 * ➀変数名
 * ➁ ➀に対してのデータ型（関数ポインタはポインタ型）
 * ➂関数ポインタが参照する先の関数が定義する「戻り値のデータ型」
 * ➃関数ポインタが参照する先の関数が定義する「引数のデータ型」
 *
 * ※※関数()とは、関数のメモリ番地に()を付与し、関数を呼び出している
 *
*/