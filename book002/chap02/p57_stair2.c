//***************************************************
/** 表示文字を1文字ずつずらして表示：２ */
//***************************************************

#include <stdio.h>

int main(void)
{
    int i, in;
    printf("何段表示しますか？\n>>");
    scanf("%d", &in);

    for (i = 1; i <= in; i++)
    {
        printf("%*d\n", i, i);
    }

    return 0;
}

/*
%*d 最小フィールド幅
アスタリスク* を指定した場合、第二引数の数値の幅が設定される
*/