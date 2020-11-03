//***************************************************
/** マスターマインド（完成版） */
//***************************************************

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include <string.h>

void makedigits(int x[]);
int check(const char[]);
void judge(const char[], const int[], int *, int *);
void print_result(int, int);

int main(void)
{
    int try_no = 0;     //入力回数
    int chk;            //入力値のチェック結果
    int hit;            //位置・数字も当たっている数字の個数
    int blow;           //数字が当たり、位置が外れている数字の個数
    int no[4];          //答えの数字の並び
    char buff[10];      //入力値の並びを格納する文字列
    clock_t start, end; //開始時刻・終了時刻

    srand(time(NULL)); //乱数の種を設定

    puts("-----Master Mind Start-----");
    puts("[４つの数字の並びを当てる]");
    puts("[同じ数字は含まれない]");
    puts("[4307 のように、連続して入力する]");
    puts("[半角英数字のみで、スペース等は含めない]");

    makedigits(no);  //４つの数字の並びを生成
    start = clock(); //計測開始

    for (int i = 0; i < 4; i++)
    {
        printf("%d", no[i]);
    }

    do
    {
        do
        {
            printf("\n4桁の数字を入力\n\n>>");
            scanf("%s", buff);

            chk = check(buff);

            //エラーチェック
            switch (chk)
            {
            case 1:
                printf("***数字は４文字で入力***");
                break;
            case 2:
                printf("***数字以外の文字が含まれる***");
                break;
            case 3:
                printf("***同じ数字は使用不可***");
                break;
            default:
                break;
            }
        } while (chk != 0);

        try_no++;
        judge(buff, no, &hit, &blow);  //判定
        print_result(hit + blow, hit); //判定結果を表示

    } while (hit < 4);

    end = clock();
    printf("%d回目で正解\n所要時間：%.1f秒", try_no, (double)(end - start) / CLOCKS_PER_SEC);

    return 0;
}

void makedigits(int x[])
{
    // srand(time(NULL));

    int i, j, val;

    //[x,y,l,m]の４つの値を生成していく
    // ４回のfor文と、それぞれの値の生成
    for (i = 0; i < 4; i++)
    {
        do
        {
            val = rand() % 10; //０～９までの乱数生成
            for (j = 0; j < i; j++)
            {
                //同じ値の場合は、breakして再度乱数生成
                if (val == x[j])
                {
                    break;
                }
            }
        } while (j < i);
        x[i] = val;
    }
}

//
int check(const char s[])
{
    int i, j;

    //error code 1：文字列が４文字ではない
    if (strlen(s) != 4)
    {
        return 1;
    }

    for (i = 0; i < 4; i++)
    {
        //error code 2：数字以外の文字が含まれる
        if (!isdigit(s[i]))
        {
            return 2;
        }
        for (j = 0; j < i; j++)
        {
            //error code 3：同一文字の含まれる
            if (s[i] == s[j])
            {
                return 3;
            }
        }
    }
    // return 0;
}
void judge(const char s[], const int no[], int *hit, int *blow)
{
    int i, j;
    *hit = *blow = 0;

    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 4; j++)
        {
            //数字が一致
            if (s[i] == '0' + no[j])
            {
                if (i == j)
                {
                    (*hit)++; //ヒット：位置も一致
                }
                else
                {
                    (*blow)++; //ブロー：位置は不一致
                }
            }
        }
    }
}
//判定結果を表示
void print_result(int snum, int sposi)
{
    if (sposi == 4)
    {
        printf("正解！！\n");
    }
    else if (snum == 0)
    {
        printf("1つもあっていない\n");
    }
    else
    {
        printf("%d個の数字が一致\n", snum);

        if (sposi == 0)
        {
            printf("位置は不一致\n");
        }
        else
        {
            printf("%d個は位置も合致\n", sposi);
        }
    }
    putchar('\n');
}