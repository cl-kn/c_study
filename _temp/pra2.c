#include <stdio.h>
#include <string.h>

//***************************************************
/**
 * メモ用
 */
//***************************************************

int main(void)
{
    // char str1[4] = {'d', 'o', 'g', '\0'};
    // printf("%s", str1);
    // printf(" %d\n", strlen(str1));

    //***********************************************

    // char str2[4] = {'c', 'a', 't', '\0'};
    // printf("%s", str2);
    // printf(" %d", strlen(str2));
    // printf("%s", str1);

    int array3[10];
    int *p;

    for (int i = 0; i < 10; i++)
    {
        printf("array3[%d] = %d\n", i, array3[i]);

        *p = array3[i];

        printf("array3[%x] = %p\n", i, &array3[i]);
        printf("******************************\n");
    }

    // for (int i = 0; i < 5; i++)
    // {
    //     array3[i] = i;
    //     printf("array3[%d] = %d\n", i, array3[i]);

    //     *p = array3[i];

    //     printf("array3[%d] = %p\n", i, &array3[i]);
    //     printf("******************************\n");
    // }

    // int array[] = {1, 2, 3};
    // printf("%d\n", &array);// 先頭アドレス値
    // printf("%d\n", &array[0]);// 〃
    // printf("%d\n", &array[1]);// 次のアドレス値
    // printf("%d\n", &array[2]);// 〃

    // char str[16];
    // char str1[12] = "DRAGON ";
    // char str2[] = "QUEST";
    // int i = 3;
    // sprintf(str, "%s%s%d\n", str1, str2, i);
    // printf(str);

    // char strArray[100];
    // char strDog[100] = "Pochi";
    // char strCat[100] = "Tama";
    // int num = 2000;

    // sprintf(strArray, "%s%s%d\n", strDog, strCat, num);
    // printf(strArray);

    // char test[100];

    // sprintf(test, "aiueo");
    // printf(test);

    return 0;
}