#include <arpa/inet.h>
#include <errno.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>

int read_in(int socket, char *buf, int len)
{
    char *s = buf;
    int slen = len;
    int c = recv(socket, s, slen, 0);
    while ((c > 0) && (s[c - 1] != '\n'))
    {
        // ポインタをc分進める。
        s += c;
        slen -= c;
        c = recv(socket, s, slen, 0);
    }

    if (c < 0)
        return c;
    else if (c == 0)
        buf[0] = '\0';
    else
        s[c - 1] = '\0';
    return len - slen;
}