//***************************************************
/** ポインタ、配列 */
//***************************************************

#include <stdio.h>

int main(void)
{
    // char array[2][3] = {{"shiba,husky,golden"}, {"mike", "persian", "mainecoon"}};
    char array[6][64] = {"shiba", "husky", "golden", "mike", "persian", "mainecoon"};

    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 12; j++)
        {
            printf("%c", array[i][j]);
        }
    }

    return 0;
}