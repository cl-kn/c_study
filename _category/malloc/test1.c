//***************************************************
/** メモリ領域の動的確保 */
//***************************************************

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int *ip; //領域格納されたアドレスを格納する
    int i, num;

    printf("input a number : ");
    scanf("%d", &num); // 確保する要素数を入力

    ip = (int *)malloc(num * sizeof(int)); //メモリ領域の確保、アドレスを代入

    for (i = 0; i < num; i++)
    {
        ip[i] = i;
    }

    for (i = 0; i < num; i++)
    {
        printf("<%d> ", ip[i]);
    }
    printf("\n");

    free(ip);
    return 0;
}

/*
入力値分の要素数nを持つint型配列ipの為のメモリ領域を動的に確保している

・malloc() に渡す引数は、「必要なメモリサイズのバイト数」
例：要素数nからなるint型配列に必要なサイズは、 n * sizeof(int)

・malloc()は、メモリ確保成功後、戻り値として先頭アドレスを返す


*/