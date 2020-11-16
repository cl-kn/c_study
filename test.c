//***************************************************
/** Git テスト用 */
//***************************************************

#include <stdio.h>

char str[] = "corgi";

void func(char *s)
{
    s[0] = 'A';
}

int main(void)
{
    printf("%s\n", str); //corgi
    func(str);
    printf("%s\n", str); //Aorgi

    return 0;
}