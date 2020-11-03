//***************************************************
/** 入出力と文字
 * getchar
 */
//**********  *****************************************

#include <stdio.h>

int main(void)
{
    int ch;

    /* getchar()で、EOFを受け取るまで、入力値を受け取る */
    while ((ch = getchar()) != EOF) {
        putchar(ch);
    }

    return 0;
}