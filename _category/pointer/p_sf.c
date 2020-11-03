//***************************************************
/** ポインタ */
//***************************************************

#include <stdio.h>

int main(void)
{
    int x = 100;
    int *p = &x;

    putchar('\n');

    printf("x [%%d] = %d (x : value)\n", x);     //100
    printf("*p [%%d] = %d\n", *p);               //100
    printf("&x [%%x] = %x (x : address)\n", &x); //xのアドレス値
    printf("p [%%x] = %x\n", p);

    puts("\n******** p++ ********\n");
    p++;

    printf("x [%%d] = %d (x : value)\n", x); //100
    printf("*p [%%d] = %x\n", *p);
    printf("&x [%%x] = %x (x : address)\n", &x); //xのアドレス値
    printf("p [%%x] = %x\n", p);

    // int xx = 500;
    // p = &xx;
    *p = 200; //segmentation fault
    printf("*p [%%d] = %d\n", *p);

    puts("\n******** p-- ********\n");
    p--;

    printf("x [%%d] = %d (x : value)\n", x);     //100
    printf("*p [%%d] = %d\n", *p);               //100
    printf("&x [%%x] = %x (x : address)\n", &x); //xのアドレス値
    printf("p [%%x] = %x\n", p);

    putchar('\n');
    return 0;
}

/*
20行目でインクリした（領域確保のみされる）ポインタ変数ｘに、200を代入しているため36行目と合わせて segmentation fault エラーが出る
*/