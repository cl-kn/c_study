//***************************************************
/** メモリ*/
//***************************************************

#include <stdio.h>
#include <string.h>

int main(void)
{
    // char a[3] = "01";
    static char a[8] = "0123456";
    char b[8];
    printf("before a[] = <%s>\n", a);

    strcpy(b, "00000000abcdefg");
    // strcpy(b, "abcdef");

    printf("after  a[] = <%s>\n", a);
    printf("after  b[] = <%s>\n", b);

    return 0;
}






/*
char型 a[8] 、b[8] ともにスタック領域であるメモリ上に領域が確保される。

スタック領域は、FILOである為、先に確保されたa[8]に、連続してb[8]の領域が確保され、strcpy()により、領域以上のサイズの値をb[8]に書き込んでいる為、連続しているa[]の領域にはみ出した分の"abcdefg"がa[]のデータを上書きしている。

「8バイト」
b[]
a[] 0 1 2 3 4 5 6 \0

ここで、strcpy()

b[] 0 0 0 0 0 0 0 0 a b c d e f g
a[] a b c d e f g \0

*/