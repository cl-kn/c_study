//***************************************************
/** バブルソート */
//***************************************************

#include <stdio.h>
#define NUM 10

void print_data(int arr[], int arr_num)
{
    int i;

    for (i = 0; i < arr_num; i++)
    {
        printf("%d, ", arr[i]);
    }
    printf("\n");
}

void bubble_sort(int arr[], int arr_num)
{
    int i, j, tmp;

    for (i = 0; i < arr_num; i++)
    {
        for (j = i + 1; j < arr_num; j++)
        {
            if (arr[i] > arr[j])
            {
                tmp = arr[i];
                arr[i] = arr[j];
                arr[j] = tmp;
            }
        }
        print_data(arr, arr_num);
    }
}

void swap()
{
}

int main(void)
{
    int arr[] = {6, 3, 1, 7, 0, 4, 8, 5, 2, 9};

    printf("---------before sort---------\n");
    print_data(arr, NUM);
    putchar('\n');
    putchar('\n');

    printf("--------- sort ---------\n");
    bubble_sort(arr, NUM);

    putchar('\n');
    putchar('\n');

    printf("---------after sort---------\n");
    print_data(arr, NUM);

    return 0;
}