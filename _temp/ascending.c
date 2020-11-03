//***************************************************
/** 昇順並び替え */
//***************************************************

#include <stdio.h>
#define DATA_NUM 10

void asc(int *, int);
void print_arr(const int *);
void input_arr(int *);
void swap(int *, int *);

int main(void)
{
    int i, arr[DATA_NUM];
    int *p_a = arr;
    input_arr(p_a);

    printf("--------------before--------------\n");
    print_arr(arr);

    printf("\n--------------after--------------\n");
    asc(p_a, DATA_NUM);
    print_arr(arr);

    return 0;
}

void asc(int *p_arr, int v)
{
    int i, j, temp;

    for (i = 0; i < v - 1; i++)
    {
        for (j = i + 1; j < v; j++)
        {
            if (p_arr[i] > p_arr[j])
            {
                swap(&p_arr[i], &p_arr[j]);
                // temp = p_arr[i];
                // p_arr[i] = p_arr[j];
                // p_arr[j] = temp;
            }
        }
    }
}

void print_arr(const int *arr)
{
    int i;
    for (i = 0; i < DATA_NUM; i++)
    {
        printf("arr[%d] = %d\n", i, arr[i]);
    }
}

void input_arr(int *arr)
{
    int i;
    printf("please enter a number\n");
    for (i = 0; i < DATA_NUM; i++)
    {
        printf("no%d >> ", i + 1);
        scanf("%d", &arr[i]);
    }
}

void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}