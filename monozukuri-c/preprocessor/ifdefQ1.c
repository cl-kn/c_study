//***************************************************
/** ifdef 機能 「条件コンパイル」
 * 課題１
 * 11/5
 * https://monozukuri-c.com/langc-ifdef/
 */
//***************************************************

#include <stdio.h>

// #define D_DEBUG_ON //デバッグ時に有効化

double arr[3] = {10.2, 22.3, 55.2};

double average(double *arr, int arr_num)
{
    double sum = 0, ave = 0;
    int i;

    for (i = 0; i < arr_num; i++)
    {
        sum += arr[i];
    }

#ifdef D_DEBUG_ON
    printf("sum = %lf", sum);
#endif

    ave = sum / arr_num;

    return ave;
}

int main(void)
{
    double ave = average(arr, 3);
    puts("\n");

    printf("ave = %lf", ave);
    puts("\n");

#if 0
    printf("Hello\n");
#else
    printf("World\n");
#endif
    return 0;
}