//***************************************************
/**  */
//***************************************************

#include <stdio.h>

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
        printf("それらの数字はまったく含まれません！\n");
    }
    else
    {
        printf("それらの数字中%d個の数字が含まれます。\n", snum);

        if (sposi == 0)
        {
            printf("位置もあっている数字はありません\n");
        }
        else
        {
            printf("その中の%d個は位置もあっています。\n", sposi);
        }
    }
    putchar('\n');
}

int main(void)
{
    char str[] = "1234";
    int no[4] = {1, 2, 5, 4};
    int hit, blow;

    judge(str, no, &hit, &blow);
    print_result(hit + blow, hit);

    return 0;
}