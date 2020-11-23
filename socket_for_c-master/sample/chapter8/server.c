// // #include <arpa/inet.h>
// #include <errno.h>
// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>
// // #include <sys/socket.h>

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
//     // クライアントから接続待ちを開始する。
//     listen(listener_d, 3);
//     puts("接続を待機しています...");

//     while (1)
//     {
//         // クライアント情報を格納していく。
//         struct sockaddr_storage client_addr;
//         unsigned int address_size = sizeof(client_addr);
//         // accept()で構造体に情報を入れ込むため、ポインタで渡す。
//         int client_d = accept(listener_d, (struct sockaddr *)&client_addr, &address_size);

//         char *msg = "hello! welcome! to my program!!!\r\n";
//         // クライアント毎のディスクリプタにメッセージを流し込む。
//         // ここはファイルの感覚と変わらない。
//         send(client_d, msg, strlen(msg), 0);
//         close(client_d);
//     }
// }