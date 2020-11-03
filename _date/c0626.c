#include <stdio.h>
#include <memory.h>

//***************************************************
/**
 * 6月26日 配列練習
 */
//***************************************************

void printArray();
void copyArray();
void printArray_memcpy();

int main(void)
{
    printArray();
    copyArray();
    printArray_memcpy();

    return 0;
}

void printArray()
{
    printf("******************printArray()******************\n");

    int array[] = {42, 22, 11, 62, 15};
    int count = sizeof(array) / sizeof(array[0]);

    for (int i = 0; i < count; i++)
    {
        printf("array[%d] = %d\n", i, array[i]);
    }
}

void copyArray()
{
    printf("******************copyArray()******************\n");

    int array1[] = {1, 3, 5, 7, 9, 11};
    int array2[] = {2, 4, 6, 8, 10, 12};
    int count = sizeof(array1) / sizeof(array1[0]);

    // array1 を出力
    printf("array2 : copy preview\n");
    for (int i = 0; i < count; i++)
    {
        printf("array2[%d] = %d\n", i, array2[i]);
    }

    // array1 を array2 へコピー
    for (int i = 0; i < count; i++)
    {
        array2[i] = array1[i];
    }

    // array2 を出力
    printf("array2 : copy after\n");
    for (int i = 0; i < count; i++)
    {
        printf("array2[%d] = %d\n", i, array2[i]);
    }
}

/*
memcpy(コピー先配列名､コピー元配列名、配列全体のサイズ)
*/

void printArray_memcpy()
{
    printf("******************memcpy()******************\n");

    int array1[] = {1, 3, 5, 7, 9, 11};
    int array2[] = {2, 4, 6, 8, 10, 12};
    int count = sizeof(array1) / sizeof(array1[0]);

    // array1 を出力
    printf("array2 : copy preview\n");
    for (int i = 0; i < count; i++)
    {
        printf("array2[%d] = %d\n", i, array2[i]);
    }

    // array1 を array2 へコピー
    memcpy(array2, array1, sizeof(array1));

    // array2 を出力
    printf("array2 : copy after\n");
    for (int i = 0; i < count; i++)
    {
        printf("array2[%d] = %d\n", i, array2[i]);
    }
}