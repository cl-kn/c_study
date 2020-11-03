//***************************************************
/** 2値の値を昇順に変更する */
//***************************************************

#include <stdio.h>

void swap(int *, int *);
void sort_asc(int *, int *);

int main(void)
{
    int x, y;
    printf("値を入力してください。\n");
    printf("x = ");
    scanf("%d", &x);
    printf("y = ");
    scanf("%d", &y);

    sort_asc(&x, &y);

    printf("値を昇順に並べ替えました。\n");
    printf("x = %d\ny = %d", x, y);

    return 0;
}

// 値を交換する関数
void swap(int *p_x, int *p_y)
{
    int temp;
    temp = *p_x;
    *p_x = *p_y;
    *p_y = temp;
}

//昇順(ascending order)に並べ替える関数
void sort_asc(int *p_x, int *p_y)
{
    if (*p_x > *p_y)
    {
        swap(p_x, p_y);
    }
}