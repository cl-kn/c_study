//***************************************************
/** sizeof演算子 */
//***************************************************

#include <stdio.h>

int main(void)
{
    int x = 12;
    char c = 'A';
    double d = 3.1415;

    char str[] = {"aiueo"};

    int x_size = sizeof(x);
    char c_size = sizeof(c);
    double d_size = sizeof(d);
    char str_size = sizeof(str);
    printf("%d",x_size);
    printf("%c",c_size);
    printf("%f",d_size);
    printf("%c",str_size);
   return 0;
}