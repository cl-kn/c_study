//***************************************************
/** ファイルへの書き込み【fputc／fputs／fprintfの使い方】
 * https://monozukuri-c.com/langc-file-write/#toc19
 * 課題3
 * 11/27
 */
//***************************************************

#include <stdio.h>

typedef struct
{
    char name[32];
    char level;
    double chakra;
} S_SKILL;

S_SKILL skillList[] = {
    {"術A", 'A', 82.3},
    {"術B", 'B', 43.5},
    {"術C", 'S', 130.8},
};

int main(void)
{
    FILE *fp = fopen("ninjya2.txt", "w");

    for (int i = 0; i < 3; i++)
    {
        fprintf(fp, "忍術名：%s 習得難易度：%c 消費チャクラ：%.1f\n", skillList[i].name, skillList[i].level, skillList[i].chakra);
    }

    fclose(fp);

    return 0;
}