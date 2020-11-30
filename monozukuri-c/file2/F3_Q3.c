//***************************************************
/** ファイルから読み込み【fgetc／fgets／fscanfの使い方】
 * https://monozukuri-c.com/langc-file-read/
 * http://www.c-tipsref.com/reference/stdio/fscanf.html
 * 課題３ fgets()
 * 11/30
 */
//***************************************************

#include <stdio.h>
#define D_STR_BUF_SIZE (256)

typedef struct
{
    char name[D_STR_BUF_SIZE]; //氏名
    int year;                  //誕生日：年
    int month;                //誕生日：月
    int day;                  //誕生日：日
    int height;                //身長（㎝）
    double weight;             //体重

} S_PLAYERS;

int main(void)
{
    FILE *fp;
    int i, data_count;
    S_PLAYERS players[D_STR_BUF_SIZE];

    //ファイルオープン
    if ((fp = fopen("player.txt", "r")) == NULL)
    {
        printf("error: can't read file.");
        return 0;
    }

    //ファイル読み込み
    i = 0;
    while (fscanf(fp, "%s %d %d %d %d %lf", &players[i].name, &players[i].year, &players[i].month, &players[i].day, &players[i].height, &players[i].weight) != EOF)
    {
        i++;
    }

    data_count = i; //ファイル行数

    fclose(fp);

    //ファイル内容表示
    for (i = 0; i < data_count; i++)
    {
        printf("%s %d %d %d %d %.1lf\n", players[i].name, players[i].year, players[i].month, players[i].day, players[i].height, players[i].weight);
    }

    return 0;
}