//***************************************************
/** define定義
 * 課題１、課題２
 * 11/5
 * https://monozukuri-c.com/langc-define/
 */
//***************************************************

#include <stdio.h>

#define D_PI (3.141592) //円周率
#define CIRCLE_LEN(r) (((r) + (r)) * D_PI)
// #define CIRCLE_LEN(r) (2 * (r)*D_PI)

//引数：半径、戻り値：円周
double getCircleLength(double radius)
{
    return (radius + radius) * D_PI;
    // return 2 * radius * D_PI;
}

int main(void)
{
    double len1 = getCircleLength(2.8 + 1.4);
    double len2 = CIRCLE_LEN(2.8 + 1.4);

    printf("%lf\n", len1);
    printf("%lf\n", len2);

    return 0;
}