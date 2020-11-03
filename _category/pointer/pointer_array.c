//***************************************************
/** ポインタと配列
 * 参考：https://monozukuri-c.com/langc-pointer-array/
*/
//***************************************************

#include <stdio.h>

void subfunc(long *pnum, int arr_num);

int main(void)
{
    long num[5] = {10, 20, 30, 40, 50};

    subfunc(num, 5);

    return 0;
}

void subfunc(long *pnum, int size)
{
    int i;

    //no1:配列的参照（単純明確）
    for (i = 0; i < size; i++)
    {
        printf("%d\n", pnum[i]);
    }

    //no2:ポインタ位置からの相対参照（あまり使わない）
    for (i = 0; i < size; i++)
    {
        printf("%d\n", *(pnum + i));
    }

    //no3:ポンタ位置をずらして参照（※先頭アドレスが変動する事に注意※）
    for (i = 0; i < size; i++)
    {
        printf("%d\n", *pnum);
        pnum++;
    }
}