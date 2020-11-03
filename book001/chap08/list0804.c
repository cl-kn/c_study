//***************************************************
/** 警告を発しながら表示を行うマクロ
 * 「コンマ演算子」
 * a,b を順に評価し、式全体ではbの評価値を生成
 */
//***************************************************

#include <stdio.h>
#define puts_alert(str) (putchar('\a'), puts(str))

int main(void)
{
    int n;
    printf("整数を入力してください >> ");
    scanf("%d",&n);

    if (n) {
        puts_alert("入力値：ゼロではない");
     }else {
        puts_alert("入力値：ゼロ");
    }

    return 0;
}
