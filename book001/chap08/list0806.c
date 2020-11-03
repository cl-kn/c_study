//***************************************************
/** 列挙型定数 */
//***************************************************

#include <stdio.h>

enum animal {Dog, Cat, Owl,Invalid}; /* enum animal型 */

void dog(void)
{
    printf("\n「ワン！」\n");
}

void cat(void)
{
    printf("\n「ニャー」\n");
}
void owl(void)
{
    printf("\n「ホーホー」\n");
}

enum animal select(void) {
    int tmp;

    do {
        printf("\n0 == 犬\n1 == 猫\n2 == フクロウ\n3 == 終了\n");
        scanf("%d",&tmp);
    }while (tmp < Dog || tmp > Invalid);
    return tmp;
}

int main(void)
{
    enum animal selected; /* enum animal型の変数、 0,1,2,3 の値をとりうる */

    do {
        switch (selected = select())
        {
        case Dog : dog();
            break;
        case Cat : cat();
            break;
        case Owl : owl();
            break;
        default:
            break;
        }
    }while (selected != Invalid);

    return 0;
}
