#include <stdio.h>
#include "calc.h"
#include "showResult.h"

int main(void)
{
    int x = 5;
    int y = 10;

    printf("%d + %d = ", x, y);
    add(x, y);
    showAnswer();
    printf("%d - %d = ", x, y);
    sub(x, y);
    showAnswer();

    return 0;
}
