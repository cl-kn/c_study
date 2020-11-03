#include <stdio.h>
#include <string.h>

//***************************************************
/**
 * 例題４ strcmp()関数
 * 辞書列順で文字列を大小比較
 *
 * strcmp( )関数は2つの文字列の大きさを比較する関数です。
 * strcmp(a, b)は文字列aと文字列bの大きさを比較するという意味になります。
 * 大小関係は辞書列順で判断されます。例えば、「a」と「z」では「z」のほうが大きくなります。
 * 返り値は
 * ・ a>bの場合は正数
 * ・ a=bの場合は0
 * ・ a<bの場合は負数
 * 文字列の同値判定に使える？？
 */
//***************************************************

int main(void)
{
    //文字列型配列の宣言と代入
    char str1[] = "ABCDE";
    char str2[] = "CDEFG";
    char str3[] = "FEHIJ";
    char str4[] = "A";
    char str5[] = "S";
    char str6[] = "ABCDF";
    char str7[] = "ABCDE";

    //判定用変数
    int i = 0;

    //str1とstr1の比較、iに代入
    i = strcmp(str1, str1);
    printf("結果 (%5s, %5s) = %2d\n", str1, str1, i);

    //str1とstr2の比較、iに代入
    i = strcmp(str1, str2);
    printf("結果 (%5s, %5s) = %2d\n", str1, str2, i);

    //str2とstr3の比較、iに代入
    i = strcmp(str2, str3);
    printf("結果 (%5s, %5s) = %2d\n", str2, str3, i);

    //str2とstr2の比較、iに代入
    i = strcmp(str2, str2);
    printf("結果 (%5s, %5s) = %2d\n", str2, str2, i);

    //str4とstr2の比較、iに代入
    i = strcmp(str4, str2);
    printf("結果 (%5s, %5s) = %2d\n", str4, str2, i);

    //str4とstr5の比較、iに代入
    i = strcmp(str4, str5);
    printf("結果 (%5s, %5s) = %2d\n", str4, str5, i);

    //str5とstr4の比較、iに代入
    i = strcmp(str5, str4);
    printf("結果 (%5s, %5s) = %2d\n", str1, str1, i);

    //str6とstr7の比較、iに代入
    i = strcmp(str6, str7);
    printf("結果 (%5s, %5s) = %2d\n", str6, str7, i);

    //str7とstr6の比較、iに代入
    i = strcmp(str7, str6);
    printf("結果 (%5s, %5s) = %2d\n", str7, str6, i);

    return 0;
}