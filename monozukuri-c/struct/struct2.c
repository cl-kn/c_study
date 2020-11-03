//***************************************************
/** 構造体２ ： アライメント、パディングについて
 * サイト：https://monozukuri-c.com/langc-struct/
 *
 * アライメント：メモリ配置ルール
 * short型 2の倍数のアドレスに配置
 * long型 4の倍数のアドレスに配置
 * 10月30日
 */
//***************************************************

#include <stdio.h>

typedef struct
{
    //サイズ 12
    char num1;  //200
    short num2; //202
    char num3;  //204
    long num4;  //208
} S_NUM;

typedef struct
{
    //サイズ 6
    char num1;  //200
    short num2; //202
    char num3;  //203
} S_NUM1;

typedef struct
{
    //サイズ 12
    long num1;
    short num2;
    long num3;
} S_NUM2;

typedef struct
{
    //サイズ 8
    long num1;
    short num2;
} S_NUM3;

int main(void)
{
    // S_NUM num;
    // S_NUM1 num1;
    // S_NUM2 num2;
    S_NUM3 num3;

    //型サイズ表示
    // printf("S_NUM num size:%d\n", sizeof(S_NUM));
    // //各メンバのアドレス表示
    // printf("S_NUM num.num1:0x%p\n", &num.num1);
    // printf("S_NUM num.num2:0x%p\n", &num.num2);
    // printf("S_NUM num.num3:0x%p\n", &num.num3);
    // printf("S_NUM num.num4:0x%p\n\n", &num.num4);

    // printf("S_NUM1 num1 size:%d\n", sizeof(S_NUM1));
    // printf("S_NUM1 num1.num1:0x%p\n", &num1.num1);
    // printf("S_NUM1 num1.num2:0x%p\n", &num1.num2);
    // printf("S_NUM1 num1.num3:0x%p\n\n", &num1.num3);

    // printf("S_NUM2 num2 size:%d\n", sizeof(S_NUM2));
    // printf("S_NUM2 num2.num1:0x%p\n", &num2.num1);
    // printf("S_NUM2 num2.num2:0x%p\n", &num2.num2);
    // printf("S_NUM2 num2.num3:0x%p\n\n", &num2.num3);

    printf("S_NUM3 num3 size:%d\n", sizeof(S_NUM3));
    printf("S_NUM3 num3.num1:0x%p\n", &num3.num1);
    printf("S_NUM3 num3.num2:0x%p\n\n", &num3.num2);

    return 0;
}