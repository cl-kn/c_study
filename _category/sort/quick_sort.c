//***************************************************
/** クイックソート
 * 参考 http://www1.cts.ne.jp/~clab/hsample/Sort/Sort9.html */
//***************************************************

#include <stdio.h>
#define NUM 10
#define NUM2 2

void quick_sort(int arr[][NUM2], int left, int right);
void print_data(int arr[][NUM2], int arr_num);
void swap(int[][NUM2], int i, int j);

int main(void)
{
    int arr[] = {6, 3, 1, 7, 5, 4, 8, 0, 2, 9};
    int arr2[][NUM2] = {{6, 0}, {3, 0}, {1, 0}, {7, 0}, {5, 0}, {4, 0}, {8, 0}, {0, 0}, {2, 0}, {9, 0}};

    printf("---------before sort---------\n");
    print_data(arr2, NUM);
    putchar('\n');
    putchar('\n');

    printf("--------- sort ---------\n");
    quick_sort(arr2, 0, NUM - 1);
    putchar('\n');
    putchar('\n');

    printf("---------after sort---------\n");
    print_data(arr2, NUM);

    return 0;
}

void quick_sort(int arr[][NUM2], int left, int right)
{
    int i, j;
    int pivot;

    i = left;  //ソートする配列の最小要素の添字
    j = right; //ソートする配列の最大要素の添字

    pivot = arr[(left + right) / 2][0]; //基準値を配列の中央付近にとる

    while (1)
    {
        while (arr[i][0] < pivot)
        {        //pivotより小さい値が
            i++; //出るまでiを増加させる
        }

        while (pivot < arr[j][0])
        {        //pivotより大きい値が
            j--; //出るまでｊを減少
        }
        if (i >= j)
        {
            break;
        }
        swap(arr, i, j);

        //次のデータ
        i++;
        j--;
    }
    // print_data(arr, NUM); //途中経過表示
    printf("   pivot = %d\n", pivot);

    //基準値の左に 2 以上要素があれば、左の配列をクイックソート
    if (left < i - 1)
    {
        quick_sort(arr, left, i - 1);
    }
    //基準値の右に 2 以上要素があれば、右の配列をクイックソート
    if (j + 1 < right)
    {
        quick_sort(arr, j + 1, right);
    }
}

void swap(int arr[][NUM2], int i, int j)
{
    int temp = arr[i][0];
    arr[i][0] = arr[j][0];
    arr[j][0] = temp;
}

void print_data(int arr[][NUM2], int arr_num)
{
    int i;

    for (i = 0; i < arr_num; i++)
    {
        printf("%d, ", arr[i][0]);
    }
    // printf("\n");
}