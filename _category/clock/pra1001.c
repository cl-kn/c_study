//***************************************************
/** clock_tなど */
//***************************************************

#include <stdio.h>
#include <time.h>

int main(void)
{
    int start, end;
    double total_time = 0.0;
    double set_time = 0.0;
    char message[] = "stop!!";

    printf("set time (sec) >>");
    scanf("%lf", &set_time);

    start = clock() / CLOCKS_PER_SEC;

    // 設定時間到達後、ループ脱出
    while (1)
    {
        if (total_time > set_time)
        {
            break;
        }
        end = clock() / CLOCKS_PER_SEC;
        total_time = end - start;
    }

    printf("%s", message);

    return 0;
}

/*
clock_t
機能：clock関数の戻り値のデータを保持する型。
定義：#include <time.h>

【戻り値】
正常時： プログラム実行開始からの経過時間（プロセッサ時間）
エラー時： (clock_t)-1 ※(clock_t)型でキャストされた-1

実装例：
#include <stdio.h>
#include <time.h>

int main(void)
{
    clock_t start = clock();
    for( int i = 0; i < 10000000; ++i ){
    }
    clock_t end = clock();

    printf( "result: %f seconds\n", (double)(end - start) / CLOCKS_PER_SEC ); //result: 0.026000 seconds

    return 0;
}



*/