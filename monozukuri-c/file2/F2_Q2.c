//***************************************************
/** https://monozukuri-c.com/langc-file-write/#toc19
 * 課題２
 * 11/27
 */
//***************************************************

#include <stdio.h>
#include <string.h>

int main(void)
{
    FILE *fp = fopen("ninjya.txt", "w");
    char * skillList[] = {"術１", "術２", "術３"};

    for (int i = 0; i < 3; i++)
    {
        fputs(skillList[i], fp);
        fputc('\n', fp);
    }

    // if ((fp = fopen("ninjya.txt", "w")) == EOF)
    // {

    //     printf("EOF error\n");
    // }
    // else
    // {

    // }

    fclose(fp);

    return 0;
}