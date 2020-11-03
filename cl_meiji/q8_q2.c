//***************************************************
/** 演習８ main関数内完結ver */
//***************************************************

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int load(char *, int *);
void store_file();
void sort(int *, int);
void reverse(int *, int *);
void print_file(char *file_name);

int main(void)
{
    int score[256], file_data_num, n = 0, i;
    char filename[] = "testdata.txt";

    FILE *fp;

    if ((fp = fopen(filename, "r")) == NULL)
    {
        printf("**** file does not open ****\n");
        exit(1);
    }

    //ファイルの中身を終端まで読み込む
    while (!feof(fp) && n < 256)
    {
        fscanf(fp, "%d", &(score[n])); //読み込んだ値を配列に格納
        n++;                           //行を進める （行のカウント数）
    }

    fclose(fp);

    n = n - 1; //EOFが含まれているので、１マイナスする

    //格納されたか確認用
    // for (i = 0; i < n; i++)
    // {
    //     printf("%d\n", score[i]);
    // }

    sort(score, n);

    // ソート後の確認用
    // for (i = 0; i < n; i++)
    // {
    //     printf("%d\n", score[i]);
    // }

    fp = fopen("result.txt", "w");

    for (i = 0; i < n; i++)
    {
        fprintf(fp, "%d\n", score[i]);
    }

    fclose(fp);

    return 0;
}

//ファイル入力関数、読み取ったデータ数を返す
int load(char *filename, int *arr)
{
    int i, n = 0, count = 0;
    FILE *fp;

    if ((fp = fopen(filename, "r")) == NULL)
    {
        printf("**** file does not open ****\n");
        exit(1);
    }

    while (!feof(fp) && n < 256)
    {
        fscanf(fp, "%d", &(arr[n]));
        n++;
        count++;
    }

    fclose(fp);

    return count;
}

//ファイル出力関数
void store_file()
{
}

//降順ソート関数
void sort(int *array, int arr_num)
{
    int i, j;
    int tmp = 0;

    for (i = 0; i < arr_num; i++)
    {
        for (j = i + 1; j < arr_num; j++)
        {
            if (array[i] < array[j])
            {
                reverse(&array[i], &array[j]);
            }
        }
    }
}

//値の入れ替え関数
void reverse(int *x, int *y)
{
    int tmp = *x;
    *x = *y;
    *y = tmp;
}

//ファイル中身表示用関数
void print_file(char *file_name)
{
    FILE *fp;

    if ((fp = fopen(file_name, "r")) == NULL)
    {
        printf("**** ^o^ file does not open ^o^ ****\n");
        exit(1);
    }
}