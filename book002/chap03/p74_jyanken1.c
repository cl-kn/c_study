//***************************************************
/** p74 じゃんけんゲーム */
//***************************************************

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
    int comp;
    int user;
    int judge;
    int retry;

    // int gu = 0;
    // int cyo = 1;
    // int pa = 2;

    srand(time(NULL));

    printf("「じゃんけんSTART!!」\n");

    do
    {
        comp = rand() % 3; // 0,1,2 の乱数

        printf("(0) グー (1) チョキ (2) パー\n>> ");
        scanf("%d", &user);
        printf("自分の手：");
        switch (user)
        {
        case 0:
            printf("グー\n");
            break;
        case 1:
            printf("チョキ\n");
            break;
        case 2:
            printf("パー\n");
            break;
        }

        printf("コンピュータの手：");
        switch (comp)
        {
        case 0:
            printf("グー\n");
            break;
        case 1:
            printf("チョキ\n");
            break;
        case 2:
            printf("パー\n");
            break;
        }

        judge = (user - comp + 3) % 3;

        switch (judge)
        {
        case 0:
            printf("引き分け！\n");
            break;
        case 1:
            printf("コンピュータの勝ち！\n");
            break;
        case 2:
            printf("あなたの勝ち！\n");
            break;

        default:
            break;
        }

        printf("\nもう一度やりますか？ はい [1] いいえ [0]\n>> ");
        scanf("%d", &retry);
    } while (retry == 1);

    return 0;
}