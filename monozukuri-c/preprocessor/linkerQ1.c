//***************************************************
/**  */
//***************************************************
#include <stdio.h>
#define  D_FRUIT_NAMESIZE  (32)

typedef struct
{
    char name[D_FRUIT_NAMESIZE];
    long price;

} S_FRUIT;

void fruitOutput(S_FRUIT fruit)
{
    if (fruit.price > 0){
        printf("名前：%s\n", fruit.name);
        printf("価格：%d\n", fruit.price);
    }
}

int main(void)
{
    S_FRUIT fruit = { "桃" , 400 };

    fruitOutput(fruit);

    return 0;
}