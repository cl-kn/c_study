//***************************************************
/** 動的メモリ【ヒープメモリの使い方と獲得する方法】

 * https://monozukuri-c.com/langc-dynamic-memory/
 * 11/13
 */
//***************************************************

#include <stdio.h>
#include <stdlib.h>

enum
{
    E_MUSIC_A, //音楽A
    E_MUSIC_B, //音楽B
};

void music(int musicKind)
{
    //確保したメモリへのポインタ
    char *pMusic = NULL;
    size_t musicSize = 0;

    if (musicKind == E_MUSIC_A)
    {
        // 1M byte
        musicSize = 1024 * 1024;
    }
    else
    {
        // 5M byte
        musicSize = 5 * 1024 * 1024;
    }

    //ヒープメモリ
    //指定サイズ分のメモリ確保
    pMusic = (char *)malloc(musicSize);

    //音楽の読み込みと再生処理・・・？？
    free(pMusic);
    pMusic = NULL;
}

int main(void)
{
    //音楽Aを再生
    music(E_MUSIC_A);

    short *p1 = NULL;
    double *p2 = NULL;

    //short型[要素数100]分の配列
    p1 = (short *)malloc(sizeof(short) * 100);

    //double型[要素数50]分の配列
    p2 = (short *)malloc(sizeof(double) * 50);

    return 0;
}

/**「動的メモリ（ヒープメモリ）」
 *「動的メモリ」「変数」「R/W」「大サイズ」「メモリ確保関数で取得」

 ・動的メモリ（ヒープメモリ）＝＝メモリ確保関数を利用する
 ・必要な分だけメモリを使用できる

 ・「malloc関数」
 * void * malloc(size_t size);
 * 仕様：確保したいヒープメモリのサイズを引数で指定する。
 * 戻り値：確保されたヒープメモリのアドレス
 * 戻り値の型：voidポインタ型
 * ・voidポインタ型（参照先のデータ型を持たない「場所を示すだけのポインタ」）
 * ・malloc関数が提供するのは、確保したメモリの範囲であり、データ型は利用する側で決定する
 * ・よって、malloc関数の戻り値であるメモリ番地を受け取る際には、対象メモリを扱うためのポインタ型へ明示的キャストが必要となる
 *
 *
 * ※ free();でメモリを解放しないと、メモリリークの恐れがある
 *
*/