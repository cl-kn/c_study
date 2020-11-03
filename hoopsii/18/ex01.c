//***************************************************
/** 演習Ｖ－１
 * 成績表の構造体
 * １：学生
 * ２：学籍番号、氏名、学年、クラス、点数（３：が要素）
 * ３：英語、国語、数学、理科、社会
*/
//***************************************************

#include <stdio.h>
#define NAME_LEN 64

typedef struct
{
    int english;
    int language;
    int math;
    int science;
    int socialstudies;

} Score;

typedef struct
{
    int number;    //学籍番号
    char *name;    //氏名
    int classYear; //学年
    char *class;   //クラス（A,B,C）
    Score score;   //構造体の入れ子

} Student;

void output(Student *p)
{
    int i = 0;

    while (p->number < 4)
    {
        printf("%d %s %d %s %3d %3d %3d %3d %3d\n",
               p->number,
               p->name,
               p->classYear,
               p->class,
               p->score.english,
               p->score.language,
               p->score.math,
               p->score.science,
               p->score.socialstudies);
        p++;
    }
}

int main(void)
{
    // 構造体の初期化
    Student students[] =
        {
            {1, "学生A", 2, "A", {88, 66, 84, 69, 80}},
            {2, "学生B", 1, "C", {100, 66, 24, 92, 55}},
            {3, "学生C", 3, "B", {55, 76, 94, 31, 75}},
        };

    Student *p;
    p = students;

    printf("学籍番号 氏名 学年 クラス 英語 国語 数学 理科 社会\n");
    output(p); //動かない関数

    // printf("%d %s %d %c", students.number, students.name, students.classYear, students.class);

    return 0;
}