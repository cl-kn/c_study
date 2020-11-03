//***************************************************
/** 5人の学生を身長の昇順にソート */
//***************************************************

#include <stdio.h>
#define NUM 5
#define NAME_LEN 64

typedef struct
{
    char name[NAME_LEN];
    int height;
    float weight;
    long schols;
} Student;

// x及びyが指す学生を交換
void swap_Student(Student *x, Student *y)
{
    Student temp = *x;
    *x = *y;
    *y = temp;
}

// 学生の配列aの先頭n個の要素を身長の昇順にソート
void sort_by_height(Student a[], int n)
{
    int i, j;

    for (i = 0; i < n - 1; i++)
    {
        for (j = n - 1; j > i; j--)
        {
            if (a[j - 1].height > a[j].height)
            {
                swap_Student(&a[j - 1], &a[j]);
            }
        }
    }
}

// 学生の配列aの先頭n個の要素を奨学金の昇順にソート
void sort_by_schols(Student a[], int n)
{
    int i, j;

    for (i = 0; i < n - 1; i++)
    {
        for (j = n - 1; j > i; j--)
        {
            if (a[j - 1].schols > a[j].schols)
            {
                swap_Student(&a[j - 1], &a[j]);
            }
        }
    }
}

// 学生の配列aの先頭n個の要素を体重の昇順にソート
void sort_by_weight(Student a[], int n)
{
    int i, j;

    for (i = 0; i < n - 1; i++)
    {
        for (j = n - 1; j > i; j--)
        {
            if (a[j - 1].weight > a[j].weight)
            {
                swap_Student(&a[j - 1], &a[j]);
            }
        }
    }
}

int main(void)
{
    int i;
    Student std[] = {
        {"Tanaka", 159, 50.2, 40},
        {"Yamada", 180, 79.5, 90},
        {"Sato", 175, 66.9, 20},
        {"Honda", 165, 59.4, 100},
        {"Akagi", 190, 89.7, 0}};

    for (i = 0; i < NUM; i++)
    {
        printf("%-8s %6d%6.1f%7ld\n", std[i].name, std[i].height, std[i].weight, std[i].schols);
    }

    puts("\nsort by height!!\n");
    sort_by_height(std, NUM);

    for (i = 0; i < NUM; i++)
    {
        printf("%-8s %6d%6.1f%7ld\n", std[i].name, std[i].height, std[i].weight, std[i].schols);
    }

    puts("\nsort by weight!!\n");
    sort_by_weight(std, NUM);
    for (i = 0; i < NUM; i++)
    {
        printf("%-8s %6d%6.1f%7ld\n", std[i].name, std[i].height, std[i].weight, std[i].schols);
    }

    puts("\nsort by schols!!\n");
    sort_by_schols(std, NUM);
    for (i = 0; i < NUM; i++)
    {
        printf("%-8s %6d%6.1f%7ld\n", std[i].name, std[i].height, std[i].weight, std[i].schols);
    }

    return 0;
}

// 「以下の要素を追加」
// キーボード入力で初期値を設定
// 何でソートするのか選択できる