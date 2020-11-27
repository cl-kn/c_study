//***************************************************
/**ファイルへの書き込み【fputc／fputs／fprintfの使い方】
 * https://monozukuri-c.com/langc-file-write/
 * 11/26、11/27
 */
//***************************************************

#include <stdio.h>

int main(void)
{
    FILE *fp = fopen("Hello.txt", "w");
    char *str = "Big\n";

    char *data1 = "コーギー";
    char data2 = 'C';
    int data3 = 2020;

    //fputc(int c, FILE *fp)
    fputc('C', fp);
    fputc('o', fp);
    fputc('r', fp);
    fputc('g', fp);
    fputc('i', fp);
    fputc('\n', fp);

    //fputs(const char *str, FILE * fp)
    fputs(str, fp);
    fputs("use fputs() Dog\n", fp);

    //fprintf(FILE *fp, const char *format, ...)
    fprintf(fp, "use fprintf %s %c %d", data1, data2, data3);

    fclose(fp);

    return 0;
}