#include <arpa/inet.h>
#include <errno.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>

#include "read_in.h"

void error(char *msg)
{
    fprintf(stderr, "%s: %s\n", msg, strerror(errno));
    exit(1);
}

char *itoa(int value, char *result, int base)
{
    // check that the base if valid
    if (base < 2 || base > 36)
    {
        *result = '\0';
        return result;
    }

    char *ptr = result, *ptr1 = result, tmp_char;
    int tmp_value;

    do
    {
        tmp_value = value;
        value /= base;
        *ptr++ = "zyxwvutsrqponmlkjihgfedcba9876543210123456789abcdefghijklmnopqrstuvwxyz"[35 + (tmp_value - value * base)];
    } while (value);

    // Apply negative sign
    if (tmp_value < 0)
        *ptr++ = '-';
    *ptr-- = '\0';
    while (ptr1 < ptr)
    {
        tmp_char = *ptr;
        *ptr-- = *ptr1;
        *ptr1++ = tmp_char;
    }
    return result;
}

int open_listener_socket()
{
    int s = socket(PF_INET, SOCK_STREAM, 0);
    if (s == -1)
        error("ソケットを開けません");

    return s;
}

void bind_to_port(int socket, int port)
{
    struct sockaddr_in name;
    name.sin_family = PF_INET;
    name.sin_port = (in_port_t)htons(port);
    name.sin_addr.s_addr = htonl(INADDR_ANY);
    // ポートの再利用について
    int reuse = 1;
    if (setsockopt(socket, SOL_SOCKET, SO_REUSEADDR, (char *)&reuse, sizeof(int)) == -1)
        error("ソケットに再利用オプションを設定できません");

    if (bind(socket, (struct sockaddr *)&name, sizeof(name)) == -1)
        error("ソケットにバインドできません");
}

void *read_and_write(void *a)
{
    int client_d = (int)a;
    char snum[200];
    // クライアントからの入力を待つ
    if (recv(client_d, snum, sizeof(snum), 0) < 0)
        error("データの受信に失敗");
    printf("received:%s", snum);

    // string -> int
    int num = atoi(snum);
    num *= 2;
    // int ->string
    itoa(num, snum, 10);
    // クライアントに送信
    if (send(client_d, snum, sizeof(snum), 0) == -1)
        error("データの送信に失敗");
    printf("send:%s\n", snum);

    close(client_d);
    return NULL;
}

int main()
{
    int thread_limit = 10;
    pthread_t threads[thread_limit];
    int socket_d = open_listener_socket();
    bind_to_port(socket_d, 30000);

    if (listen(socket_d, 10) == -1)
        error("listenに失敗");
    puts("接続を待機しています...");

    void *result;
    for (int thread_n = 0;; thread_n++)
    {
        struct sockaddr_storage client_addr;
        unsigned int address_size = sizeof(client_addr);
        int client_d = accept(socket_d, (struct sockaddr *)&client_addr, &address_size);

        if (client_d == -1)
            error("クライアントとのディスクリプタの作成に失敗");

        if (pthread_create(&threads[thread_n % thread_limit], NULL, read_and_write, (void *)client_d) == -1)
            error("スレッドの作成に失敗");
    }

    return 0;
}