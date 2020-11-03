//***************************************************
/** 自由課題
 * [1-1]おみくじプログラム
 * ０から６の乱数を生成
 * 大吉＞吉＞中吉＞小吉＞末吉＞凶＞大凶
 */
//***************************************************

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main(void)
{
    // int in;
    // char flag[64];
    srand(time(NULL));
    int num = rand() % 7;

    // printf("******おみくじ******\n０から６の数値を入力して下さい \n>>\n");
    // scanf("%d", &in);
    printf("******おみくじ******\n結果：");

    switch (num)
    {
    case 0:
        puts("大凶！");
        break;
    case 1:
        puts("凶");
        break;
    case 2:
        puts("末吉");
        break;
    case 3:
        puts("小吉");
        break;
    case 4:
        puts("中吉");
        break;
    case 5:
        puts("吉");
        break;
    case 6:
        puts("大吉");
        break;
    default:
        break;
    }

    return 0;
}