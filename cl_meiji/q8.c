//***************************************************
/** 第8回：ファイルと配列、関数
 * 用語：EOF (End Of File)
 * ファイルの終端には、文字列と同様終端を指す「EOF」がついている
 *
 * feof()関数
 * 用途：ファイルfpの終端指示子の ON/OFF チェック
*/
//***************************************************

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int i, n = 0;
    float f_array[64];

    FILE *fp;

    if ((fp = fopen("testNum.txt", "r")) == NULL)
    {
        printf("**** file does not open ****\n");
        exit(1);
    }

    //ファイルの中身を終端まで読み込む
    while (!feof(fp) && n < 64)
    {
        fscanf(fp, "%f", &(f_array[n])); //読み込んだ値を配列に格納

        //特定文字出現時に、何らかの処理
        /**
         * 1 特定文字のカウントする処理
         * 2 特定文字を利用した処理
        */

        n++;                             //行を進める （行のカウント数）
    }

    fclose(fp);

    n = n - 1; //EOFが含まれているので、１マイナスする
    for (i = 0; i < n; i++)
    {
        printf("%f\n", f_array[i]);
    }

    return 0;
}