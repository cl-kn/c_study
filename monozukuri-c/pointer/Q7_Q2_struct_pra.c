//***************************************************
/** 「アロー演算子の使い方【ポインタから構造体を使う】
」
 * 課題２ 復習用
 * https://monozukuri-c.com/langc-pointer-struct/
 * 11/10
 */
//***************************************************

#include <stdio.h>

typedef struct
{
    long japaneseLanguage; //国語
    long arithmetic;       //算数
    long science;          //理科
    long socialStudies;    //社会

} S_Subject;

//教科毎の平均値を算出する関数
int getAverageSubject(S_Subject pSub[], int pSub_num, S_Subject *pAve)
{
    S_Subject ave = {0};
    int i;

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
    S_Subject point[] = {
        {97, 98, 96, 100}, //学生A
        {56, 41, 100, 73}, //学生B
        {24, 11, 55, 51},  //学生C
        {78, 94, 44, 98}  //学生D
    };

    S_Subject ave = {0};

    if (getAverageSubject(point, sizeof(point) / sizeof(point[0]), &ave) < 0)
    {
        printf("ERROR");
    }
    else
    {
        printf("国語:%d\n", ave.japaneseLanguage);
        printf("算数:%d\n", ave.arithmetic);
        printf("理科:%d\n", ave.science);
        printf("社会:%d\n", ave.socialStudies);
    }

    return 0;
}

/**
 * 構造体 S_Subject
 * メンバ long型
    japaneseLanguage;      //国語
    long arithmetic;       //算数
    long science;          //理科
    long socialStudies;    //社会
 *
 * 関数 getAverageSubject
 * 引数 (構造体、要素数、平均点用)
 * 戻り値
 *
*/