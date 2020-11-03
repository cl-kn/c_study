//***************************************************
/**  自動車の移動
 * メンバ：要素数（まとめたものは１つとして扱う）
 * 構成メンバ：全要素数
*/
//***************************************************

#include <stdio.h>
#include <math.h>

#define sqr(n) ((n) * (n)) //二乗を求める

//点の座標を表す構造体
typedef struct
{
    double x;
    double y;
} Point;

//自動車を表す構造体
typedef struct
{
    Point pt;    //現在位置
    double fuel; //燃料
} Car;

// 点pa と 点pbの距離を返す
double distance_of(Point pa, Point pb)
{
    return sqrt(sqr(pa.x - pb.x) + sqr(pa.y - pb.y));
}

//自動車の現在位置と残り燃料を表示
void print_info(Car c)
{
    printf("現在位置：(%.2f.%.2f)\n", c.pt.x, c.pt.y);
    printf("残り燃料：%.2fリットル\n", c.fuel);
}

// cの指す車を目的座標destに移動
int move(Car *c, Point dest)
{
    double d = distance_of(c->pt, dest); // 移動距離

    //移動距離が燃料を超過＝＝移動不可
    if (d > c->fuel)
    {
        return 0;
    }
    c->pt = dest; // 現在位置を更新
    c->fuel -= d; // 移動距離d分の燃料を減らす

    return 1; // 移動成功
}

int main(void)
{
    Car mycar = {{0.0, 0.0}, 90.0}; // 初期化子を設定

    while (1)
    {
        int select;
        Point dest;

        print_info(mycar);
        printf("移動しますか [Yes...1 / No...0]\n");
        scanf("%d", &select);

        if (select != 1)
            break;

        printf("目的地のX座標: ");
        scanf("%lf", &dest.x);
        printf("目的地のY座標: ");
        scanf("%lf", &dest.y);

        if (!move(&mycar, dest))
        {
            puts("\a燃料不足のため移動不可！");
        }
    }
    return 0;
}