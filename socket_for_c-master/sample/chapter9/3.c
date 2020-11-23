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

void *foo(void *a)
{
    for (int i = 0; i < 5; i++)
    {
        sleep(1);
        puts("foo!");
    }
    return NULL;
}

void *hoge(void *a)
{
    for (int i = 0; i < 5; i++)
    {
        sleep(1);
        puts("hoge!");
    }
    return NULL;
}

int main()
{
    pthread_t t0;
    pthread_t t1;
    if (pthread_create(&t0, NULL, foo, NULL) == -1)
        error("スレッドt0の作成失敗");

    if (pthread_create(&t1, NULL, hoge, NULL) == -1)
        error("スレッドt0の作成失敗");

    void *result;
    if (pthread_join(t0, &result) == -1)
        error("スレッドt0のジョインに失敗");

    if (pthread_join(t1, &result) == -1)
        error("スレッドt1のジョインに失敗");
}