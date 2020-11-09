//***************************************************
/** 「ポインタと配列【類似点と相違点から知る正しい扱い方】」
 * https://monozukuri-c.com/langc-pointer-array/
 * 11/9
 */
//***************************************************

#include <stdio.h>

//配列を内包する構造体定義
typedef struct
{
    int num[10];
} S_PACK;

void func(S_PACK pack)
{
    //配列[0]を書き換え
    pack.num[0] = 12345;
    return;
}

int main(void)
{
    S_PACK data;

    data.num[0] = 555;

    func(data);//実行しても、元の配列に影響しない

    printf("%d\n", data.num[0]); //555

    return 0;
}