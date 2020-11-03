//***************************************************
/** 列挙型 enum ：
 * サイト：https://monozukuri-c.com/langc-enum/
 *
 *・連番の定数（定められた数）を生成する
 *・enum は int型と等しい
 *
 * 11月3日
 */
//***************************************************

#include <stdio.h>

//列挙型に型名を付けて定義（名前があると判り易い）
typedef enum
{
    E_FRUIT_ORANGE,
    E_FRUIT_BANANA,
    E_FRUIT_PEACH,
    E_FRUIT_APPLE = 10,
    E_FRUIT_GRAPE,

    //---
    E_FRUIT_END //番兵

} E_FRUIT;

int printFruit(E_FRUIT fruit)
{
    //値の範囲チェック
    if (fruit < 0 || E_FRUIT_END <= fruit)
    {
        //値が0未満か、番兵以上のとき、不正な値
        return -1;
    }
    //処理
}

int main(void)
{
    int fruit1 = E_FRUIT_ORANGE; // 0
    E_FRUIT fruit2 = E_FRUIT_BANANA;

    switch (fruit2)
    {
    case E_FRUIT_APPLE:
        printf("リンゴ");
        break;
    case E_FRUIT_ORANGE:
        printf("オレンジ");

    case E_FRUIT_GRAPE:
        printf("ぶどう");
        break;

    default:
        break;
    }

    return 0;
}

/**「列挙型のメリット」
 * ・数値情報に名前を付けられる為、可読性が向上する
 * ・定数値を自動付与する
 * ・switchとの組み合わせ
 *
 * 「注意点」
 * ・列挙子に不正な値（未定義など）を代入しても、エラーが出ない
 * ・慣例として、定数値には大文字を付ける 例：E_列挙型名
 *
 * ※ 列挙型の値の範囲チェックには、番兵を利用すると便利
 *
 *
 *
*/