//***************************************************
/** 学生を表す構造体 */
//***************************************************

#include <stdio.h>
#include <string.h>
#define NAME_LEN 64

// 構造体の定義
struct dog
{
    /* data */
    char name[NAME_LEN];  // 名前
    char breed[NAME_LEN]; //犬種
    char color[NAME_LEN]; //毛の色
    float weight;         //体重
};

int main(void)
{
    struct dog pochi = {"ポチ", "柴犬", "茶", 10};

    printf("名前：%s\n", pochi.name);
    printf("犬種：%s\n", pochi.breed);
    printf("毛の色：%s色\n", pochi.color);
    printf("体重：%.1f\nkg", pochi.weight);

    return 0;
}