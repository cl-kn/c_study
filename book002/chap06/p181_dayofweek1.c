//***************************************************
/** 曜日を求める１：mktime() */
//***************************************************

#include <stdio.h>
#include <time.h>

int day_of_week(int, int, int);

int main(void)
{
    int year = 2020, month = 10, day = 2, w;
    char *ws[] = {"日", "月", "火", "水", "木", "金", "土"};

    // printf("曜日を求めます\n");
    // printf("年：");
    // scanf("%d", &year);
    // printf("月：");
    // scanf("%d", &month);
    // printf("日：");
    // scanf("%d", &day);

    w = day_of_week(year, month, day);

    if (w != -1)
    {
        printf("%s曜日\n", ws[w]);
    }
    else
    {
        printf("取得に失敗しました。\n");
    }

    return 0;
}

int day_of_week(int year, int month, int day)
{
    struct tm t;

    t.tm_year = year - 1900; // 年月日の情報を代入
    t.tm_mon = month - 1;
    t.tm_mday = day;
    t.tm_hour = 0;
    t.tm_min = 0;
    t.tm_sec = 0;
    t.tm_isdst = -1; // 夏時間

    //変換に失敗した場合の処理
    if (mktime(&t) == (time_t)-1)
    {
        return -1;
    }

    return t.tm_wday; // mktime()で設定された曜日を返却（年月日から自動的に求められる）
}

/*
mktime()

【書式】 <time.h>
time_t mktime(struct tm *tp)

【説明】
tpが指す構造体の時刻をtime関数が使う時刻と同じ形式の時刻に変換する
構造体tmのメンバ値が適正な値でないとき、mktime()内で調整される
（曜日などを空白にし、この関数で適切な値を求められる）

【引数】
struct tm *tp : tm構造体へのポインタ

【戻り値】
正常時：変換された時刻
異常時：（time_t）-1

※構造体 tm は、 time.h の中で宣言され、以下の情報を含む

struct tm {
    int tm_sec;  秒 [0-61] 最大2秒までのうるう秒を考慮
    int tm_min;    分 [0-59]
    int tm_hour;   時 [0-23]
    int tm_mday;   日 [1-31]
    int tm_mon;    月 [0-11] 0から始まることに注意
    int tm_year;   年 [1900からの経過年数]
    int tm_wday;   曜日 [0:日 1:月 ... 6:土]
    int tm_yday;   年内の通し日数 [0-365] 0から始まることに注意
    int tm_isdst; 夏時間フラグ [夏時間を採用しているときに正、採用していないときに 0、この情報が得られないときに負]
};



* /