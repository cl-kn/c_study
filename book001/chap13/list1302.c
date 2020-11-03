//***************************************************
/** ファイルから情報を読み込み、平均値を求める */
//***************************************************

#include <stdio.h>

int main(void)
{
    FILE *fp;
    int number = 0;
    char name[64];
    double height, weight;
    double hsum = 0.0;
    double wsum = 0.0;

    if ((fp = fopen("sample.dat", "r")) == NULL)
    {
        printf("file open failed !!\n");
    }
    else
    {
        while (fscanf(fp, "%s%lf%lf", name, &height, &weight) == 3)
        {
            printf("%-10s %5.1f %5.1f \n", name, height, weight);
            number++;
            hsum += height;
            wsum += weight;
        }
        printf("-----------------------------------------\n");
        printf("平均        %5.1f %5.1f\n", hsum / number, wsum / number);
        fclose(fp);
    }

    return 0;
}