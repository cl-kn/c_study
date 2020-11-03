//***************************************************
/** p98 じゃんけんゲーム
 * 勝負数の制限
*/
//***************************************************

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void initialize(void);
void jyanken(void);
void count_no(int);
void disp_result(int);
// int confirm_retry(void);

int user;    //ユーザーの手
int comp;    //コンピュータの手
int win_no;  //買った回数
int lose_no; //負けた回数
int draw_no; //引き分けた回数

char *hand[] = {"グー", "チョキ", "パー"}; //じゃんけんの手

int main(void)
{
    int judge;
    // int retry;

    initialize();

    do
    {
        jyanken();

        printf("ユーザーの手：%s\nコンピュータの手：%s\n", hand[user], hand[comp]);

        judge = (user - comp + 3) % 3;
        count_no(judge);
        disp_result(judge);
        // retry = confirm_retry();

        // whileの条件式に入れると１行ですむ
        // if (win_no == 3 || lose_no == 3){
        //     break;
        // }

    } while (!(win_no == 3 || lose_no == 3));

    printf(win_no == 3 ? "*****あなたの勝ち！！*****\n" : "*****コンピュータの勝ち！！*****\n");
    printf("*****勝敗結果*****\n%d勝%d敗%d分け", win_no, lose_no, draw_no);

    return 0;
}

//初期処理
void initialize(void)
{
    win_no = 0;
    lose_no = 0;
    draw_no = 0;

    srand(time(NULL));
    printf("*****じゃんけん開始*****\n");
}

void jyanken(void)
{
    int i;
    comp = rand() % 3; // コンピュータの手：乱数の０～２

    do
    {
        for (i = 0; i < 3; i++)
        {
            printf(" (%d)%s ", i, hand[i]);
        }
        printf(" : ");
        scanf("%d", &user);
    } while (user < 0 || user > 2);
}

//勝ち・負け・引き分け回数を更新
void count_no(int result)
{
    switch (result)
    {
    case 0:
        draw_no++;
        break;

    case 1:
        lose_no++;
        break;
    case 2:
        win_no++;
        break;
    }
}

//判定結果を表示
void disp_result(int result)
{
    switch (result)
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
}

// 再度実行するか確認
// int confirm_retry(void)
// {
//     int x;
//     printf("再度挑戦しますか？.....(1)はい...(0)いいえ\n>> ");
//     scanf("%d", &x);
//     return x;
// }
