//***************************************************
/** int型の数値の読み取り
 * atoi()関数
*/
//***************************************************

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    char temp[20];
    scanf("%s", temp);
    printf("input number = %d", atoi(temp));

    return 0;
}
