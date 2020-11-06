//***************************************************
/** プリプロセッサ
 * 「define]」マクロ定義
 * 11/4 , 11/5
 */
//***************************************************

#include <stdio.h>

//マクロ定義 慣例で、大文字、引数名の大文字
#define D_KIND_APPLE_ID (1) //リンゴID
#define D_KIND_PEACH_ID (2) //モモID
#define D_KIND_MELON_ID (3) //メロンID
#define PI (3.141592)       //円周率
#define D_HELLO "Hello" //文字列もマクロ定義可能

//三角形の面積を求める関数マクロ
#define triangle(base, high) ((base) * (high) / 2.0)

void printPrice(int kind)
{
    switch (kind)
    {
    case D_KIND_APPLE_ID:
        printf("300円\n");
        break;

    case D_KIND_PEACH_ID:
        printf("500円\n");
        break;

    case D_KIND_MELON_ID:
        printf("1000円\n");
        break;

    default:
        break;
    }
}

int main(void)
{
    double area;

    printPrice(2); //値段表示

    //面積の算出と表示
    //((10.0) * (30.0) / 2.0)へ置換
    area = triangle(10.0, 30.0);
    printf("%lf\n", area);

    return 0;
}

/**
 * マクロ定義 define
 * ・文字列をプログラム中で値に置換する
 * ・プリプロセッサがこれを読み取り、修正する
 * ・定数値の一括変更が便利
 * ・値の型の制限がない
 *
 * 関数マクロ定義
 * ・
 *
*/