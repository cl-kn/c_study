#include <arpa/inet.h>
#include <errno.h>
#include <netdb.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>

int main()
{
    int server_d = socket(PF_INET, SOCK_STREAM, 0);

    struct sockaddr_in si;
    memset(&si, 0, sizeof(si));
    si.sin_family = PF_INET;
    // アドレス
    si.sin_addr.s_addr = inet_addr("127.0.0.1");
    // ポート
    si.sin_port = htons(30000);
    connect(server_d, (struct sockaddr *)&si, sizeof(si));

    char snum[200];
    printf("send a number:");
    fgets(snum, sizeof(snum), stdin);

    // サーバーに送信する
    send(server_d, snum, strlen(snum), 0);

    // サーバーからの受信を待機する
    recv(server_d, snum, 200, 0);
    printf("received:%s", snum);

    close(server_d);
}