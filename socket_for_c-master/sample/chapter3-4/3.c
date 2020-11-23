#include <stdio.h>

int main()
{
    FILE *my_file = fopen("my_file", "a");
    dup2(fileno(my_file), 1);
    // printf は 標準出力、つまりはディスクプリタ1に出力を行う。
    printf("who are you?\n");
    printf("are you file?\n");
}