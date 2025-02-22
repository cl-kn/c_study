#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <mbctype.h>

//***************************************************
/**
 * ポインタのメモ用
 */
//***************************************************

int main(void)
{
    int i = 10;
    double d = 3.1415;
    char c = 'A';

    int i_value;
    double d_value;
    char c_value;

    int *p_i;
    double *p_d;
    char *p_c;

    p_i = &i;
    p_d = &d;
    p_c = &c;

    i_value = *p_i;
    d_value = *p_d;
    c_value = *p_c;

    printf("[p_i, p_d, p_c : address]\n");
    printf("%p\n", p_i);
    printf("%p\n", p_d);
    printf("%p\n", p_c);
    printf("*****************************\n");

    printf("[p_i, p_d, p_c : value(i_value, d_value, c_value)]\n");
    printf("p_i : %d\n", i_value);
    printf("p_d : %d\n", d_value);
    printf("p_c : %d\n", c_value);
    printf("*****************************\n");

    printf("[p_i, p_d, p_c : value(*p_i, *p_d, *p_c)]\n");
    printf("p_i : %d\n", *p_i);
    printf("p_d : %f\n", *p_d);
    printf("p_c : %c\n", *p_c);

    return 0;
}