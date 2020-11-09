//***************************************************
/** 「アロー演算子の使い方【ポインタから構造体を使う】
」
 * 課題１
 * https://monozukuri-c.com/langc-pointer-struct/
 * 11/9
 */
//***************************************************

#include <stdio.h>

typedef struct
{
    double latitude;  // 緯度
    double longitude; //経度
} S_Coordinate;

int getTokyoTowerPosition(S_Coordinate *pPos)
{
    if (pPos == NULL)
    {
        return 1;
    }

    pPos->latitude = 35.658581;
    pPos->longitude = 139.745433;

    return 0;
}

int main(void)
{
    S_Coordinate data;
    S_Coordinate *p_data = &data;

    if (getTokyoTowerPosition(p_data) == 1)
    {
        printf("ERROR\n");
    }
    else
    {
        printf("緯度：%f 経度：%f", p_data->latitude, p_data->longitude);
    }

    return 0;
}