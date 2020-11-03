//***************************************************
/** typedef宣言
 * 型の同義語を作る宣言（※新しい型を作るのではない）
*/
//***************************************************

#include <stdio.h>

int main(void)
{
    typedef int intkun;

    intkun x = 55;
    int y = 10;
    printf("intkun型： x = %d\n", x);
    printf("int型： y = %d\n", y);

    return 0;
}