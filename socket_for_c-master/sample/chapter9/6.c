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

int beers = 2000000;
// 正体はマクロ
pthread_mutex_t beers_lock = PTHREAD_MUTEX_INITIALIZER;
void *drink_lots(void *a)
{
    for (int i = 0; i < 100000; i++)
    {
        pthread_mutex_lock(&beers_lock);
        beers = beers - 1;
        pthread_mutex_unlock(&beers_lock);
    }
    printf("beers = %i\n", beers);
    return NULL;
}

int main()
{
    pthread_t threads[20];
    int t;

    printf("壁にはビールが%i本\n%i本のビール\n", beers, beers);
    for (t = 0; t < 20; t++)
    {
        if (pthread_create(&threads[t], NULL, drink_lots, NULL) == -1)
            error("スレッドの作成失敗");
    }
    void *result;
    for (t = 0; t < 20; t++)
    {
        if (pthread_join(threads[t], &result) == -1)
            error("スレッドのジョインに失敗");
    }

    printf("現在,壁にはビールが%i本あります\n", beers);
    return 0;
}