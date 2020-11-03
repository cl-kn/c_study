#include <stdio.h>

//***************************************************
/**
 *
 */
//***************************************************

void bubble(int[]);

int main(void)
{
    int i, array[256];
    printf("整数を入力してください。\n終了キー>> 00");

    for (i = 0; i < (sizeof(array) / sizeof(int)); i++)
    {
        scanf("%d", &array[i]);
        if (array[i] == 0)
        {
            //ENDを表示させないように i を減らす
            i--;
            break;
        }
        i++;
    }

    return 0;
}

void bubble(int array[])
{
}