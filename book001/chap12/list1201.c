//***************************************************
/** 5人の学生の名前と身長を新調の昇順にソート
 * strcpy(char *s, const char *y)関数
 * 文字列をコピーする関数
 * const char *y を、 char *s へコピー
*/
//***************************************************

#include <stdio.h>
#include <string.h>

#define NUMBER 5
#define NAME_LEN 64

void swap_int(int *, int *);
void swap_str(char *, char *);
void sort(int[], char str[][NAME_LEN], int n);

int main(void)
{
    // 変数、配列（犬の年齢、名前）の宣言
    int i;
    int age[] = {12, 15, 3, 18, 6};
    char name[][NAME_LEN] = {"Pochi", "Ken", "Akira", "Hachi", "Yamato"};

    // 犬の一覧表示
    puts("[Dog's]");
    for (i = 0; i < NUMBER; i++)
    {
        printf("%2d : %-8s%4d\n", i + 1, name[i], age[i]);
    }

    //犬の年齢を昇順ソート
    sort(age, name, NUMBER);

    printf("\n昇順にソートしました！\n\n");

    puts("[Dog's]");
    for (i = 0; i < NUMBER; i++)
    {
        printf("%2d : %-8s%4d year old\n", i + 1, name[i], age[i]);
    }

    return 0;
}

// 値の交換用
void swap_int(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

// sx及びsyが指す文字列を交換
void swap_str(char *sx, char *sy)
{
    char temp[NAME_LEN];

    //strcpy()関数の利用
    strcpy(temp, sx);
    strcpy(sx, sy);
    strcpy(sy, temp);
}

// 配列numとstrの先頭n個の要素をnumに基づいて昇順にソート
// 引数（年齢、名前の配列、要素数）
void sort(int num[], char str[][NAME_LEN], int n)
{
    int i, j;

    for (i = 0; i < n - 1; i++)
    {
        for (j = n - 1; j > i; j--)
        {
            //2つの要素の値を比較
            if (num[j - 1] > num[j])
            {
                //名前、年齢を同時に入れ替える
                swap_int(&num[j - 1], &num[j]);
                swap_str(str[j - 1], str[j]);
            }
        }
    }
}

/*
構造体を使っていないので、データの追加が不便
*/
