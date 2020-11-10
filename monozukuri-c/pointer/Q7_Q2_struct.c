//***************************************************
/** 「アロー演算子の使い方【ポインタから構造体を使う】
」
 * 課題２
 * https://monozukuri-c.com/langc-pointer-struct/
 * 11/10
 */
//***************************************************

#include <stdio.h>

#define D_ARR_NUM 4

typedef struct
{
    long japaneseLanguage; //国語
    long arithmetic;       //算数
    long science;          //理科
    long socialStudies;    //社会

} S_Subject;

/*
pSub[]     テスト結果用配列
pSub_num   テスト結果配列の要素数
pAve       平均の出力先
*/
int getAverageSubject(S_Subject pSub[], int pSub_num, S_Subject *pAve)
{
    // if (pSub == NULL)
    // {
    //     return 1;
    // }

    S_Subject ave = {0};

    int i, j;

    for (i = 0; i < pSub_num; i++)
    {
        ave.japaneseLanguage += pSub[i].japaneseLanguage;
        ave.arithmetic += pSub[i].arithmetic;
        ave.science += pSub[i].science;
        ave.socialStudies += pSub[i].socialStudies;
    }

    ave.japaneseLanguage /= pSub_num;
    ave.arithmetic /= pSub_num;
    ave.science /= pSub_num;
    ave.socialStudies /= pSub_num;

    *pAve = ave;

    return 0;
}

int main(void)
{
    //学生の教科毎のテスト結果
    S_Subject point[] = {
        {72, 85, 54, 61}, //学生A
        {50, 43, 38, 49}, //学生B
        {89, 92, 87, 78}, //学生C
        {72, 25, 36, 98}, //学生D
    };

    //平均点格納用の構造体
    S_Subject ave = {0};

    // double ave = 0;
    // double *p_ave = &ave;

    int ret = getAverageSubject(point, sizeof(point) / sizeof(point[0]), &ave);

    if (ret < 0)
    {
        printf("ERROR\n");
    }
    else
    {
        printf("*****教科別平均点*****\n");
        printf("国語：%d\n", ave.japaneseLanguage);
        printf("算数：%d\n", ave.arithmetic);
        printf("理科：%d\n", ave.science);
        printf("社会：%d\n", ave.socialStudies);
    }

    return 0;
}