//***************************************************
/** 演習８
 * ・1行ずつ得点が記入されたテキストファイルを読み込み、降順にソートして順位付けを行い、別のファイルに出力するプログラム
 * ・重複する得点は同じ順位にする
*/
//***************************************************

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int load(char *, int *);
void store_file(int);
void sort(int *, int);
void swap(int *, int *);
void print_file(char *);
void copy_arr(int *, int);
void add_rank(int *, int);

int input_score[256];
int rank_value[200][2]; //{得点,順位}のセット

int main(void)
{
    int file_data_num;
    char filename[] = "testdata.txt";

    file_data_num = load(filename, input_score); //ファイル内データ数取得
    sort(input_score, file_data_num);            //降順ソート
    add_rank(input_score, file_data_num);        //順位付与

    //コピー確認用
    // for (int i = 0; i < file_data_num; i++)
    // {
    //     printf("%d,%d\n", rank_value[i][0], rank_value[i][1]);
    // }

    store_file(file_data_num); //ファイル書き出し

    return 0;
}

//ファイル入力関数、読み取ったデータ数を返す
int load(char *filename, int *arr)
{
    int i, n = 0;
    FILE *fp;

    if ((fp = fopen(filename, "r")) == NULL)
    {
        printf("**** can't open the file ^v^ ****\n");
        exit(1);
    }

    while (!feof(fp) && n < 256)
    {
        fscanf(fp, "%d", &(arr[n]));
        n++;
    }

    fclose(fp);

    n = n - 1; //EOF行の除外

    return n;
}

//ファイル出力関数
void store_file(int file_data_num)
{
    FILE *fp;
    int i;
    char store_filename[64];

    printf("Enter a output file name >>");
    scanf("%s", store_filename);

    fp = fopen(store_filename, "w");

    fprintf(fp, "score,rank\n");
    for (i = 0; i < file_data_num; i++)
    {
        fprintf(fp, "%d,%d\n", rank_value[i][0], rank_value[i][1]);
    }

    fclose(fp);
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
                swap(&array[i], &array[j]);
            }
        }
    }
}

//値の入れ替え関数
void swap(int *x, int *y)
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
        printf("**** can't open the file ^v^ ****\n");
        exit(1);
    }
}

//配列コピー関数：memcpy()不使用
void copy_arr(int *score_arr, int arr_num)
{
    int i, j;
    for (i = 0; i < arr_num; i++)
    {
        rank_value[i][0] = score_arr[i];
    }
}

//値の順位付け関数（重複順位は合算したい）
void add_rank(int *score_arr, int arr_num)
{
    int i, j;
    int rank = 0;  //順位用変数
    int value = 0; //得点の同値比較用変数

    copy_arr(score_arr, arr_num);

    rank_value[0][1] = rank;

    for (i = 0; i < arr_num; i++)
    {
        if (rank_value[i][0] != value)
        {
            rank++;
        }
        rank_value[i][1] = rank;
        value = rank_value[i][0];
    }
}

/**
 * 順位付けメモ
 * 100,1
 * 99,2
 * 98,3
 * 98,3
 * 97,5
 * ↑のように、得点に対して順位をつける
 * 重複点数は同位とする
 *
 * 「方法１」無駄
 * ・順位を表示する配列を用意
 * ・配列内に得点を格納し、添え字を順位として利用
 *
 * rank[200] = {0,100,99,98,97,・・・} ※先頭に0を付与し、1位から表示
 *
 * 「方法２」無駄
 * ・2次元配列を用意し、降順ソート後の配列をコピーする
 * ・{得点,順位}のセット
 *
 * {{100,1},{99,2},{98,3},{98,3},{97,5}・・・}
*/