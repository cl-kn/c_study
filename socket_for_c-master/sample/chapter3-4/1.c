#include <stdio.h>

int main()
{
    FILE *my_file = fopen("my_file", "a");

    printf("my_file_discripter_number:%d\n", fileno(my_file));

    fprintf(my_file, "hogehoge\n");
    // printf("foo!!!\n")
    fprintf(stdout, "foo!!!\n");

    fclose(my_file);
    return 0;
}