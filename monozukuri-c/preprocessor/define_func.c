//***************************************************
/** プリプロセッサ
 * 「define]」マクロ定義
 * 関数マクロの副作用
 * https://monozukuri-c.com/langc-define/
 * 11/5
 */
//***************************************************

#include <stdio.h>

#define triangle(base, high) ((base) * (high) / 2.0) //三角形の面積を求める関数マクロ
#define square(side) ((side) * (side))               // 正方形の面積を求める関数マクロ
#define MAX_false(a, b) (((a) > (b)) ? (a) : (b))    //関数マクロ：副作用
#define ERROR_MACRO(a, b) (a * b)                    //関数マクロ：副作用２

int main(void)
{
    //面積の算出と表示
    // ((10.0) * (30.0) / 2.0)へ置換
    double area_triangle = triangle(10.0, 30.0);
    printf("triangle area = %lf\n", area_triangle);

    //正方形の面積の算出と表示
    // ((10.0) * (10.0))
    double area_square = square(10.0);
    printf("square area = %lf\n", area_square);

    int x = 10, y = 20;
    int value1 = MAX_false(++x, --y);

    printf("MAX_false = %d\n", MAX_false(++x, --y));

    //関数の副作用
    printf("ERROR_MACRO = %d\n", ERROR_MACRO(1 + 2, 3 + 4)); // 11
    //上記コード
    // 期待 ( (1 + 2) * (3 + 4)) = 21
    // 結果 ( 1 + 2 * 3 + 4 ) = 11

    return 0;
}