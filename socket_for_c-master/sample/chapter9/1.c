#include <errno.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

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
    foo(NULL);
    hoge(NULL);
}