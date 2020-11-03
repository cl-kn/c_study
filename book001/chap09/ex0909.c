//***************************************************
/** 演習９－９
 * 入力文字列を反転して返す ※strlen()を使わない場合
 * void rev_string(char str[]) {}
 */
//***************************************************

#include <stdio.h>
int str_length(const char[]);
void rev_string(char str[]);

int main(void)
{
    int i;
    char str[256];

    puts("文字列を入力して下さい");
    scanf("%s", str);

    rev_string(str);

    puts("文字列を逆順に並べ替えました");
    puts(str);

    return 0;
}

//文字列strの長さを返す strlen()未使用
int str_length(const char str[])
{
    int len = 0;

    //1文字ごとにカウント
    while (str[len])
    {
        len++;
    }
    printf("文字数：%d\n", len);
    return len;
}

//文字列を逆順にして返す
void rev_string(char str[])
{
    int i;
    int len = str_length(str);

    //並び替える回数を決定し、並び替え
    for (i = 0; i < len / 2; i++)
    {
        char temp = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = temp;
    }
}

/*


 */