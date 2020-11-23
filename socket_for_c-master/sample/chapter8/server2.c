// #include <arpa/inet.h>
// #include <errno.h>
// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>
// #include <sys/socket.h>

// char *itoa(int value, char *result, int base)
// {
//     // check that the base if valid
//     if (base < 2 || base > 36)
//     {
//         *result = '\0';
//         return result;
//     }

//     char *ptr = result, *ptr1 = result, tmp_char;
//     int tmp_value;

//     do
//     {
//         tmp_value = value;
//         value /= base;
//         *ptr++ = "zyxwvutsrqponmlkjihgfedcba9876543210123456789abcdefghijklmnopqrstuvwxyz"[35 + (tmp_value - value * base)];
//     } while (value);

//     // Apply negative sign
//     if (tmp_value < 0)
//         *ptr++ = '-';
//     *ptr-- = '\0';
//     while (ptr1 < ptr)
//     {
//         tmp_char = *ptr;
//         *ptr-- = *ptr1;
//         *ptr1++ = tmp_char;
//     }
//     return result;
// }

// int main()
// {
//     // https://linuxjm.osdn.jp/html/LDP_man-pages/man2/socket.2.html
//     int listener_d = socket(PF_INET, SOCK_STREAM, 0);

//     // ソケット名はプロトコルとポート番号が必要
//     struct sockaddr_in name;
//     // インターンネットプロトコルを指定
//     name.sin_family = PF_INET;
//     // ポート番号
//     name.sin_port = (in_port_t)htons(30000);

//     // bind() にはソケットディスクリプタ,ソケット名が必要
//     bind(listener_d, (struct sockaddr *)&name, sizeof(name));

//     // listen() はソケットに対して待ち行列を指定して
//     // 受け入れクライアントから接続待ちを開始する。
//     listen(listener_d, 10);
//     puts("接続を待機しています...");

//     while (1)
//     {
//         // クライアント情報を格納していく。
//         struct sockaddr_storage client_addr;
//         unsigned int address_size = sizeof(client_addr);
//         // accept()で構造体に情報を入れ込むため、ポインタで渡す。
//         int client_d = accept(listener_d, (struct sockaddr *)&client_addr, &address_size);

//         char *snum;
//         // クライアントからの入力を待つ
//         recv(client_d, snum, 200, 0);
//         printf("received:%s", snum);

//         // string -> int
//         int num = atoi(snum);
//         num *= 2;
//         // int ->string
//         itoa(num, snum, 10);
//         // クライアントに送信
//         send(client_d, snum, sizeof(snum), 0);
//         printf("send:%s\n", snum);

//         close(client_d);
//     }
// }