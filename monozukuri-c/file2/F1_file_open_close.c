//***************************************************
/** ファイルの開き方・閉じ方【fopenとfcloseの使い方】
 * https://monozukuri-c.com/langc-file-open-close/
 * 11/26
 */
//***************************************************

// #define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
    //FILE構造体をポインタ変数で用意
    FILE *fp1 = NULL;
    FILE *fp2 = NULL;

    //fopen()の戻り値(ファイルハンドル)をFILEポインタ型変数に代入
    fp1 = fopen("memo1.txt", "w");
    fp2 = fopen("memo2.txt", "w");

    fclose(fp1);
    fclose(fp2);

    //*****************************************************
    //fopen_s()関数の場合


    return 0;
}

/**
 * 「fopen()」
 * ・ファイル制御のための標準ライブラリ関数
 *関数仕様：FILE * fopen(const char * filename, const char * mode);
 *引数１：ファイル名
 *引数２：開くモード
 *戻り値：ファイルハンドル（ファイルディスクリプタ）
 *異常：NULLポインタが返却
 *
 * 「fclose()」
 * ・fopen()で開いたファイルを閉じる
 * 関数仕様：int fclose(FILE * fp);
 * 引数１：閉じるファイルハンドルを指定
 * 戻り値：正常時０、異常時EOF
 * 特記事項：引数には必ずfopen()を呼び出した時のファイルハンドルを渡す
 *
 * 「FILE構造体」
 *・ファイルを管理するための情報が詰め込まれたデータ
 *・fopen()を呼び出す→FILE構造体のメモリ確保→メモリ番地が戻り値で返却
 *・上記のハンドルのメモリ領域は「ヒープメモリ」に確保
*/