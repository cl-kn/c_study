#include <errno.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void error(char *msg)
{
    fprintf(stderr, "%s: %s\n", msg, strerror(errno));
    exit(1);
}

void *do_stuff(void *param)
{
    long thread_no = (long)param;
    printf("スレッド番号%ld\n", thread_no);
    return (void *)(thread_no + 1);
}

int main()
{
    pthread_t threads[3];
    long t;
    for (t = 0; t < 3; t++)
    {
        // longを渡すときにはvoid* に変換
        if (pthread_create(&threads[t], NULL, do_stuff, (void *)t) == -1)
            error("スレッド生成に失敗");
    }

    void *result;
    for (t = 0; t < 3; t++)
    {
        // ここで、threads[t]が合流する
        if (pthread_join(threads[t], &result) == -1)
            error("スレッドジョインに失敗");
        // void* で帰ってくるのでlongに変換する
        printf("スレッド%ldは%ldを返しました\n", t, (long)result);
    }
    return 0;
}