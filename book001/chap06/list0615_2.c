//***************************************************
/**  */
//***************************************************

#include <stdio.h>
#define FAILED -1
#define KEY 2

int main(void)
{
    int arr[5] = {15, 22, 31, 47, 54};

    printf("探索するキー：%d\n", KEY);

    int i = 0;
    /* 番兵を格納 */
    /* 配列の最後尾に番兵を格納 */
    arr[6] = KEY;

    // while を for文で書き換え
    for (i; arr[i] != KEY; i++)
    {
        printf("arr[%d] = %d >>>>no\n", i, arr[i]);
    };
    if (arr[i] == KEY)
    {
        printf("arr[%d] = %d >>>>hit!!\n", arr[i], KEY);
    }

    return 0;
}
