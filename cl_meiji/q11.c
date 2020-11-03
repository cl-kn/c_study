//***************************************************
/**
 * 参考：http://www.isc.meiji.ac.jp/~re00079/EX2.2011/20110713.html
 */
//***************************************************

#include <stdio.h>

int main(void)
{
    int score[][2] = {
        {65, 71},
        {84, 83},
        {74, 74},
        {90, 90},
        {87, 78},
        {93, 95},
    };

    int score2[12] = {65, 71, 84, 83, 74, 74, 90, 90, 87, 78, 93, 95};

    int i, j, personSum, scoreSumA = 0, scoreSumB = 0;
    double averageA = 0, averageB = 0;

    for (i = 0; i < 6; i++)
    {
        personSum = 0;
        for (j = 0; j < 2; j++)
        {
            personSum += score[i][j];
        }
        printf("出席番号[%d] 2科目合計 [%d点]\n", i + 1, personSum);
        scoreSumA += score[i][0];
        scoreSumB += score[i][1];
        // printf();
    }
    averageA = scoreSumA / 6;
    averageB = scoreSumB / 6;

    printf("語学平均 %.1f\n", averageA);
    printf("力学平均 %.1f\n", averageB);

    return 0;
}