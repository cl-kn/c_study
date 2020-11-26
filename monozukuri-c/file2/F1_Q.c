//***************************************************
/** https://monozukuri-c.com/langc-file-open-close/
 * ファイルの開き方・閉じ方【fopenとfcloseの使い方】
 * 課題 11/26
 */
//***************************************************

#include <stdio.h>

int main(void)
{
    FILE *fp = NULL;

    if (fp = fopen("Hello.txt","r") == NULL) {
        printf("file open failed\n");
        // return;
    }else {
        printf("file open success\n");
        fclose(fp);
    }

    // fclose(fp);

    return 0;
}