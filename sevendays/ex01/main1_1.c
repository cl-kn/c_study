#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
    int a, b;

    //乱数の初期化
    //参考 http://c-lang.sevendays-study.com/ex-day1.html
    srand((unsigned)time(NULL));

    //１～１０までの乱数を発生
    // 余りの結果が０～９で、＋１により１～１０までの乱数を生成
    a = rand() % 10 + 1;
    b = rand() % 10 + 1;

    //結果を出力
    printf("%d + %d = %d\n", a, b, a + b);

    return 0;
}
