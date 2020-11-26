//***************************************************
/** 演習A
 * http://www.cc.kyoto-su.ac.jp/~hxm/cstext/prog06.html
 * 11/26
 */
//***************************************************

#include <stdio.h>
#include "cstext.h"

int sum = 0;

int main(void)
{
    int i;

    for (i = 1; i <= NUM; i++)
    {
        add(&sum,i);
        printf("total=%d\n", sum);
    }
    return 0;
}