//***************************************************
/** 2点間の距離を求める */
//***************************************************

#include <stdio.h>
#include <math.h>

#define sqr(n) ((n) * (n)) //2乗値を求める

// 点の座標を表す構造体

typedef struct
{
    double x; //x座標
    double y; // y座標
} Point;

// 点pa と、点pb の距離を返す
double distance_of(Point pa, Point pb)
{
    return sqrt(sqr(pa.x - pb.x) + sqr(pa.y - pb.y));
}

int main(void)
{
    Point crnt, dest;

    printf("現在地のX座標: ");
    scanf("%lf", &crnt.x);
    printf("現在地のY座標: ");
    scanf("%lf", &crnt.y);

    printf("目的地のX座標: ");
    scanf("%lf", &dest.x);
    printf("目的地のY座標: ");
    scanf("%lf", &dest.y);

    printf("目的地までの距離：%lf", distance_of(crnt, dest));

    return 0;
}