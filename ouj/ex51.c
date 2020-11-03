#include <stdio.h>
#include <ctype.h>

int main(void)
{
    char c;

    printf("１文字入力してください > ");
    scanf("%c", &c);

    printf("%c を大文字にすると、 %c です。", c, toupper(c));

    return 0;
}

// toupper()・・・小文字を大文字に！！