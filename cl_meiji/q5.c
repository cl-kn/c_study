//***************************************************
/** 第5回：関数(1) */
//***************************************************

#include <stdio.h>
#define NUM 5

int test2(int *);
void zero_init(int *, int);
int rectarea(int vertical, int width);
double arr_average(int *, int);

int main(void)
{
    int a = 2, b = 3, x = 0, y = 0, i;
    int *pa, *pb;

    a = b;   // 値参照
    pa = pb; //アドレス参照

    char str[] = "abc";
    printf("%s\n", str); // 配列の先頭アドレス値を渡している
    puts("---------------------------------------------");

    //address参照の確認
    printf("enter value x == ");
    scanf("%d", &x);

    y = test2(&x); //x,yともに値が変更される
    // test2(&x);
    printf("y = %d\n", y);
    printf("x = %d\n", x);

    puts("---------------------------------------------");

    int arr[] = {10, 20, 30, 40, 50};

    //配列変更前
    for (i = 0; i < NUM; i++)
    {
        printf("%d, ", arr[i]);
    }
    puts("\n");
    zero_init(arr, NUM);

    //配列変更後
    for (i = 0; i < NUM; i++)
    {
        printf("%d, ", arr[i]);
    }

    puts("\n---------------------------------------------");
    int xx, yy;

    printf("vertical >> ");
    scanf("%d", &xx);
    printf("width >> ");
    scanf("%d", &yy);

    printf("[%d]\n", rectarea(xx, yy));
    puts("\n---------------------------------------------");

    int test_arr[NUM];
    float f;

    for (i = 0; i < NUM; i++)
    {
        scanf("%d", &(test_arr[i]));
    }

    for (i = 0; i < NUM; i++)
    {
        printf("%d, ", test_arr[i]);
    }

    f = arr_average(test_arr, NUM);

    printf("average = %f\n", f);

    return 0;
}

// ポインタ変数を2乗して返す関数
int test2(int *p)
{
    *p *= *p;
    return *p;
}

//全配列の要素に０を代入する
void zero_init(int *p, int arr_num)
{
    int i;
    for (i = 0; i < arr_num; i++)
    {
        *(p + i) = 0;
    }
}

//長方形の面積を求める関数
int rectarea(int vertical, int width)
{
    int value;

    value = vertical * width;

    return value;
}

//配列の平均値を返す関数
double arr_average(int *arr, int arr_num)
{
    int sum = 0, i;
    double average = 0;

    for (i = 0; i < arr_num; i++)
    {
        sum += arr[i];
    }

    return average = (sum / arr_num);
}
