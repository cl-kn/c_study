#include <stdio.h>
#include <string.h>

//***************************************************
/**
 * 3-1 文字列の結合
 */
//***************************************************

int main(void)
{
    char familyName[256];
    char firstName[256];

    printf("familyName >> ");
    scanf("%s", &familyName);
    printf("firstName >> ");
    scanf("%s", &firstName);

    strcat(familyName, firstName);
    printf("fullName == %s\n", familyName);

    return 0;
}