//***************************************************
/** EOFの値と数値文字の値 */
//***************************************************

#include <stdio.h>

int main(void)
{
    int i;
    printf("EOF(end of file) = %d\n",EOF);

    for (i = 0; i < 10; i++) {

        printf("'%d' = %d\n",i, '0' + i);

    }

    return 0;
}