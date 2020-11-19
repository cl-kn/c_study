//***************************************************
/** ポインタを使った文字列の扱い方と注意点
 * https://monozukuri-c.com/langc-string-middle/
 * 11/17、11/18、11/19
 * ～文字列・メモリ制御ライブラリから考察するポインタの使い方～まで
 * 「関数仕様から関数の作りをイメージする」
 * strlen()
 * strcpy_s()
 */
//***************************************************

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

size_t strlen_my(const char *str);
int strcpy_s_my(char *arr, int arr_size, const char *src);
int strcat_s_my(char *arr, int arr_size, const char *src);
void *memcpy_my(void *m_after, const void *m_before, int copy_size);
// void print_str(char *str);

int main(void)
{
//strlen_my()の確認
#if 0
    char *str1 = "corgi";
    printf("%d\n", strlen_my(str1)); //5
#endif

//strcpy_s_my()の確認
#if 0
    char *str2 = "CORGI";
    char strcopy[100];

    if (strcpy_s_my(strcopy, strlen_my(str2) + 1, str2) < 0)
    {
        printf("ERROR\n");
    }
    else
    {
        printf("%s\n", strcopy); //corgi
    }
#endif

//strcat_s_my()の確認
#if 0
    char str3[100] = "Hello"; //結合元、文字列配列
    char str4[] = "World";    //結合する、文字列配列

    strcat_s_my(str3, 100, str4);
    printf("%s", str3); //HelloWorld
#endif

//memcpy_my()の確認
#if 1
    //1Byte
    char src1 = 'a';
    char dst1 = 'b';

    //4Byte
    long src2 = 123;
    long dst2 = 456;

    memcpy_my(&dst1, &src1, sizeof(char));
    memcpy_my(&dst2, &src2, sizeof(long));

    printf("%c\n", dst1);
    printf("%d\n", dst2);

#endif
    return 0;
}

//strlen関数
//文字列の長さを返す
size_t strlen_my(const char *str)
{
    // int i,count;
    // for (i = 0; i < ; i++) {
    // }
    //**********************************************************
    size_t len = 0;

    while (*str != '\0')
    {
        len++; //文字列長さをカウント
        str++; //ポインタ照準を移動
    }

    return len;
}

//strcpy_s関数
//文字列を別の配列へコピーする
int strcpy_s_my(char *arr, int arr_size, const char *src)
{
    // int i;
    // while (src[i] != arr[i])
    // {
    //     arr[i] = src[i];
    // }
    //**********************************************************
    //ヌル文字含めた長さ取得
    int len = strlen(src) + 1;
    int i;

    //コピー先配列サイズ確認
    if (arr_size < len)
    {
        return -1;
    }

    //文字列コピー
    for (i = 0; i < len; i++)
    {
        arr[i] = src[i];
    }
    return 0;
}

//strcat_s_my関数
//文字列を結合する
//※ arr には、結合後の文字列サイズが格納できるサイズを確保する
int strcat_s_my(char *arr, int arr_size, const char *src)
{
#if 1 //解答版
    //ヌル文字含めた長さ取得
    int len = strlen_my(arr) * strlen_my(src) + 1;

    //配列サイズ確認
    if (arr_size < len)
    {
        return -1;
    }

    // 結合前終端までarrポインタを移動
    while (*arr != '\0')
    {
        arr++;
    }

    //結合文字を順次収納
    while (*src != '\0')
    {
        *arr = *src;
        arr++;
        src++;
    }

    //終端文字を格納
    *arr = '\0';

#else //以下、自作版
    int src_len = strlen_my(src);
    // int arr_len = strlen_my(arr);
    int i = 0, j;

    if (src_len > arr_size)
    {
        return -1;
    }

    while (1)
    {
        if (arr[i] == '\0')
        {
            for (j = 0; j < src_len; j++)
            {
                arr[i] = src[j];
                i++;
            }
            break;
        }
        i++;
    }
#endif

    return 0;
}

//メモリデータをコピーする関数
//引数１ m_after   コピー先メモリ
//引数２ m_before  コピー元メモリ
//引数３ copy_size データ型サイズ
void *memcpy_my(void *m_after, const void *m_before, int copy_size)
{
    //m_afterをcharポインタ型へ変換
    //型のあるポインタ型へ明示的キャストを行うことで、
    //char型データへのポイントとなった？？
    char *dst = (char *)m_after;

    //m_beforeをcharポインタ型へ変換
    char *src = (char *)m_before;

    int i;

    //指定サイズのメモリコピー
    for (i = 0; i < copy_size; i++)
    {
        dst[i] = src[i];
    }

    return m_after;
}

//文字列を出力する関数
#if 0
void print_str(char *str)
{
    printf("%s\n", str);
}
#endif

/**「文字列制御関数」
 *
 * strlen [文字列の長さを取得]
 * strcpy_s [文字列をコピー]
 * strcat_s [文字列を結合]
 * memcpy [メモリデータをコピー]
 *
 * ※文字列は終端文字'\n'で終わることが約束されている
 * ※よって、引数に配列サイズを渡さない関数もある
 * 
*/