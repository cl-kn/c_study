#include <stdio.h>
#include <string.h>

int main()
{
    FILE *data_file = fopen("data", "r");
    char *name;
    int age;
    fscanf(data_file, "%s %d", name, &age);

    FILE *takao_profile = fopen("takao_profile", "w");
    fprintf(takao_profile, "name:%s age:%d\n", name, age);

    fclose(data_file);
    fclose(takao_profile);
    return 0;
}