//***************************************************
/**  */
//***************************************************

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int getUserHand();
int getCpHand();
int judge(int, int);
void printResult(int);

int userHand;
int cpHand;
char *hands[] = {"グー", "チョキ", "パー"};

int main(void)
{
    getUserHand();
    getCpHand();
    printResult(judge(userHand, cpHand));
    return 0;
}

//userの手を取得
int getUserHand()
{
    printf("じゃんけんスタート！\nあなたの手を選んでください\n[0]...グー [1]...チョキ [2]...パー\n>> ");
    scanf("%d", &userHand);
    return userHand;
}

// cpの手を返す
int getCpHand()
{
    srand(time(NULL));
    cpHand = rand() % 3;
}

//判定結果を返す
int judge(int userHandNum, int cpHandNum)
{
    int judgeNum = (userHandNum - cpHandNum + 3) % 3;
    return judgeNum;
}

//判定結果を表示する
void printResult(int judgeNum)
{
    printf("あなた「%s」 ***VS*** CP「%s」\n", hands[userHand], hands[cpHand]);

    switch (judgeNum)
    {
    case 0:
        printf("「引き分け」です。");
        break;
    case 1:
        printf("「CPの勝ち」です");
        break;
    case 2:
        printf("「あなたの勝ち」です。");
        break;
    default:
        break;
    }
}

/*
追加
・再度じゃんけんできる（ループ）
・繰り返すかを選択できる
・勝敗を記録して表示する
*/