//***************************************************
/** 7章：演習（３）
 *解答
 */
//***************************************************

#include <stdio.h>
#include <math.h>

int main(void)
{
    int i;
    double rad, pi;
    FILE *fp;

    pi = 3.141;

    fp = fopen("sin.csv", "w");

    for (i = 0; i <= 360; i++)
    {
        rad = i / 180.0 * pi;
        fprintf(fp, "%f\n", sin(rad));
    }

    fclose(fp);

    return 0;
}