//***************************************************
/** ポインタ変数定義の正しい解釈とは【＊の意味を解説】
 * https://monozukuri-c.com/langc-pointer-interpretation/
 *
 * 11/9
 */
//***************************************************

#include <stdio.h>

//課題１
void getEdisonBirthday(long *pYear, unsigned char *pMonth, unsigned short *pDay)
{
    *pYear = 1847;
    *pMonth = 2;
    *pDay = 11;

    return;
}

int main(void)
{
    long year;
    char month;
    short day;
    getEdisonBirthday(&year, &month, &day);
    printf("誕生日：%d年%d月%d日\n", year, month, day);

    return 0;
}

/**「ポインタ変数」復習
 * int num = 100;
 * int *p_num = &num;
 *
 * ポインタ変数自身のアドレス（*）とデータ型へのアドレス（num）、
 *※ p_num のint型 がない場合、参照先メモリの型が特定できないので、
 ポインタ変数のデータ型は、必ず参照先変数のデータ型と一致させる
 *
 * 「＊の意味について」
 *
 * void func(long * bow) {   //➀
 *      long num = 20 * 50;  //➁
 *      *bow = num;          //➂
 *      return 0;
 * }
 *
 * ➀ポインタ変数の定義時に使用。変数がポインタ型であることを示す
 *  （long型変数の値を、ポインタ変数bowが受け取る？）
 * ➁定数や変数に対して乗算を行うことを示す
 * ➂ポインタが指し示す番地のメモリを示す
 *
 * 「間接参照演算子」
 *  pnum = &num; // 変数numのアドレスを、ポインタ変数pnumに代入
 *  *pnum = 100; // pnumの参照先メモリに100を書き込む
 *
*/