//***************************************************
/** じゃんけんゲーム： */
//***************************************************

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void judge(int, int);
void jyanken(void);

int main(void)
{
    jyanken();

    return 0;
}

void judge(int user, int comp)
{
    int flag;
    flag = (user - comp + 3) % 3;

    switch (flag)
    {
    case 0:
        printf("引き分け\n");
        break;
    case 1:
        printf("コンピュータの勝ち\n");
        break;
    case 2:
        printf("ユーザーの勝ち\n");
        break;

    default:
        break;
    }
}

void jyanken(void)
{
    int comp;
    int user;
    int judge;
    int retry;
    int i;

    char *jyankens[] = {"グー", "チョキ", "パー"};

    srand(time(NULL));

    printf("******じゃんけん******\n");

    do
    {
        comp = rand() % 3; // 0,1,2 の乱数

        do
        {
            for (i = 0; i < 3; i++)
            {
                printf(" (%d)%s ", i, jyankens[i]);
            }
            printf(" : ");
            scanf("%d", &user);

        } while (user < 0 || user > 2);

        printf("自分の手 : %s\nコンピュータの手 ： %s\n", jyankens[user], jyankens[comp]);

        judge(user, comp);

        printf("\nもう一度やりますか？ はい [1] いいえ [0]\n>> ");
        scanf("%d", &retry);
    } while (retry == 1);
}
