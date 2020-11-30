//***************************************************
/**  ファイルから読み込み【fgetc／fgets／fscanfの使い方】
 * https://monozukuri-c.com/langc-file-read/
 * 11/27
*/
//***************************************************

#include <stdio.h>

int main(void)
{
#if 0
    //fgetc()
    FILE *fp = fopen("Hello.txt", "r");
    char c;

    while ((c = fgetc(fp)) != EOF)
    {
        printf("%c", c);
    }

    fclose(fp);

#endif

#if 0
    //fgets()
    FILE *fp2 = fopen("num2.txt", "r");
    char str[256];

    while (fgets(str, 256, fp2) != NULL)
    {
        printf("%s", str);
    }

    fclose(fp2);

#endif

#if 1

    FILE *fp3 = fopen("meibo.txt", "r");
    char name[32] = {0};
    int age = 0;
    double height = 0;
    char blood_type = 0;

    while (fscanf(fp3, "%s %d %lf %c", name, &age, &height, &blood_type) != EOF)
    {
        printf("%s %d %3.2lf %c\n", name, age, height, blood_type);
    }

    // fscanf(fp3, "%s %d %lf %c", name, &age, &height, &blood_type);
    // printf("%s %d %3.2lf %c\n", name, age, height, blood_type);

    fclose(fp3);

#endif

    return 0;
}