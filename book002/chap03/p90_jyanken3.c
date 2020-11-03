//***************************************************
/** p90 じゃんけんゲーム 改変版
 * ポインタへの配列を利用する
*/
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
    int i;

    char *jyanken[] = {"グー", "チョキ", "パー"};

    srand(time(NULL));

    printf("******じゃんけん******\n");

    do
    {
        comp = rand() % 3; // 0,1,2 の乱数

        do
        {
            for (i = 0; i < 3; i++)
            {
                printf(" (%d)%s ", i, jyanken[i]);
            }
            printf(" : ");
            scanf("%d", &user);

        } while (user < 0 || user > 2);

        printf("自分の手 : %s\nコンピュータの手 ： %s\n", jyanken[user], jyanken[comp]);

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