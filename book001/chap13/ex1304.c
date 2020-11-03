//***************************************************
/** 複数人の名前・身長・体重を読み込み、ファイルに書き込む */
//***************************************************

#include <stdio.h>
#define NAME_LEN 64

struct Date
{
    double height;
    double weight;
};

typedef struct
{
    char name[NAME_LEN];
    struct Date human_date;
} Human;

int main(void)
{
    FILE *fp;
    int i;

    Human member = {
        {"田中", {159,55,}}


        };

    for (i = 0; i < 5; i++)
    {
    printf("no.%d\n",i);
    printf("name >> ");
    scanf("%s",name);
    printf("height >> ");
    scanf();
    printf("weight >> ");
    scanf();
    }

    return 0;
}